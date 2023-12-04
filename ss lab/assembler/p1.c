#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char opcode[10], operand[10], label[10], ch, temp1[20], temp2[20], temp3[20];
int locctr, start, len, stN = -1, otN = -1, i, j = 0, flag, size = 0, opd;
FILE *inputFile, *opcodeFile, *symtabFile, *intermediateFile, *lengthFile;

struct SYMTAB {
  char label[10];
  int addr;
} ST[10];

struct OPTAB {
  char opcode[10], hexcode[10];
} OT[10];

void read_optab() {
  while (1) {
    otN++;
    fscanf(opcodeFile, "%s%s", OT[otN].opcode, OT[otN].hexcode);
    if (getc(opcodeFile) == EOF)
      break;
  }
}

void read_line() {
  strcpy(temp1, "");
  strcpy(temp2, "");
  strcpy(temp3, "");
  fscanf(inputFile, "%s", temp1);
  if (getc(inputFile) != '\n') {
    fscanf(inputFile, "%s", temp2);
    if (getc(inputFile) != '\n')
      fscanf(inputFile, "%s", temp3);
  }
  if (strcmp(temp1, "") != 0 && strcmp(temp2, "") != 0 &&
      strcmp(temp3, "") != 0) {
    strcpy(label, temp1);
    strcpy(opcode, temp2);
    strcpy(operand, temp3);
  } else if (strcmp(temp1, "") != 0 && strcmp(temp2, "") != 0 &&
             strcmp(temp3, "") == 0) {
    strcpy(label, "");
    strcpy(opcode, temp1);
    strcpy(operand, temp2);
  } else if (strcmp(temp1, "") != 0 && strcmp(temp2, "") == 0 &&
             strcmp(temp3, "") == 0) {
    strcpy(label, "");
    strcpy(opcode, temp1);
    strcpy(operand, "");
  }
}

int main(int argc, char const *argv[]) {
  inputFile = fopen("./input/input.txt", "r");
  opcodeFile = fopen("./input/opcode.txt", "r");
  symtabFile = fopen("./p1out/symtab.txt", "w");
  intermediateFile = fopen("./p1out/intermediate.txt", "w");
  lengthFile = fopen("./p1out/length.txt", "w");

  read_optab();

  fscanf(inputFile, "%s%s%x", label, opcode, &opd);
  if (strcmp(opcode, "START") == 0) {
    start = opd;
    locctr = start;
    fprintf(intermediateFile, "\t%s\t%s\t%x\n", label, opcode, opd);
    read_line();
  } else
    locctr = 0;

  while (strcmp(opcode, "END") != 0) {
    fprintf(intermediateFile, "%x\t%s\t%s\t%s\n", locctr, label, opcode,
            operand);
    if (strcmp(label, "") != 0) {
      for (i = 0; i <= stN; i++) {
        if (strcmp(ST[i].label, label) == 0) {
          printf("!!Error!!Symbol already present");
          exit(0);
        }
      }
      stN++;
      strcpy(ST[stN].label, label);
      ST[stN].addr = locctr;
    }
    flag = 0;
    for (i = 0; i <= otN; i++) {
      if (strcmp(opcode, OT[i].opcode) == 0) {
        locctr += 0x3;
        size += 3;
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      if (strcmp(opcode, "WORD") == 0) {
        locctr += 0x3;
        size += 3;
      } else if (strcmp(opcode, "RESW") == 0)
        locctr += 0x3 * (atoi(operand));
      else if (strcmp(opcode, "RESB") == 0)
        locctr += atoi(operand);
      else if (strcmp(opcode, "BYTE") == 0) {
        len = strlen(operand);
        if (operand[0] == 'C' || operand[0] == 'c')
          len -= 3;
        else
          len = (len - 3) / 2;
        locctr += len;
        size += len;
      }
    }
    read_line();
  }
  fprintf(intermediateFile, "\t%s\t%s\t%s\n", label, opcode, operand);
  for (i = 0; i <= stN; i++) {
    fprintf(symtabFile, "%s\t%x", ST[i].label, ST[i].addr);
    if (i != stN)
      fprintf(symtabFile, "\n");
  }
  fprintf(lengthFile, "%x\n%x", locctr - start, size);
  fclose(inputFile);
  fclose(opcodeFile);
  fclose(symtabFile);
  fclose(intermediateFile);
  fclose(lengthFile);
}