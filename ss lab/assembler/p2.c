#include <stdio.h>

FILE *intermediateFile, *opTabFile, *symTabFile, *objcode, *lengthFile;
int opTabSize = -1, symTabSize = -1;
char sym[10], symAddr[10];
char programName[10], startAddr[10], length[10];

// a bunch of temp strings
char t1[10], t2[10], t3[10];
int c = 6; // cuz why not

struct symTabStruct {
  char label[10];
  char addr[10];
} symTab[10];

struct opTabStruct {
  char operand[10];
  char opcode[10];
} opTab[10];

void loadSymTab() {
  while (1) {
    symTabSize++;
    fscanf(symTabFile, "%s%s", symTab[symTabSize].label,
           symTab[symTabSize].addr);
    if (fgetc(symTabFile) == EOF)
      break;
  }
}

// int getLength(char str[]) {
//   while (getc(programName) != '\0') {
//     c--;
//   }
//   return c;
// }

void loadOpTab() {
  while (1) {
    opTabSize++;
    fscanf(opTabFile, "%s%s", opTab[opTabSize].opcode, opTab[opTabSize].opcode);
    if (fgetc(opTabFile) == EOF)
      break;
  }
}

void readIntermediate() {
  fscanf(intermediateFile, "%s\tSTART\t%s", programName, startAddr);

  fprintf(objcode, "H^%s  ^00%s^%s%s\n\nT^00%s^", programName, startAddr,
          length, startAddr);
  
  
}

int main(int argc, char const *argv[]) {

  // open files
  intermediateFile = fopen("./p1out/intermediate.txt", "r");
  opTabFile = fopen("./input/input.txt", "r");
  symTabFile = fopen("./p1out/symtab.txt", "r");
  lengthFile = fopen("./p1out/length.txt", "r");

  objcode = fopen("objcode.txt", "w");

  // read length
  fscanf(lengthFile, "%s", length);
  fclose(lengthFile);

  // load and close opTab and symTab
  loadOpTab();
  fclose(opTabFile);
  loadSymTab();
  fclose(symTabFile);

  readIntermediate();
  fclose(intermediateFile);

  return 0;
}