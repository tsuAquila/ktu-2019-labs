#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *iptr, *outptr;
char record[100];
char starting_address[100];
int recordpointer;

void writeToOutputFile() {
  char objectcode[7];
  int address;
  address = strtol(starting_address, NULL, 16);
  while (record[recordpointer] != '\0') {
    // printf("\n%s\n", record);

    fprintf(outptr, "%x\t", address);
    strncpy(objectcode, record + recordpointer, 6);
    fprintf(outptr, "%s\n", objectcode);
    recordpointer += 7;
    address += 3;

    printf("%c\n", record[recordpointer]);
  }
}

int main() {
  iptr = fopen("inputfile.txt", "r");
  outptr = fopen("outputfile.txt", "w");

  if (iptr == NULL)
    printf("Kindly Enter a Valid File");

  fgets(record, 100, iptr);

  while (record[0] != 'E') {
    // printf("\n%s\n", record);

    if (record[0] == 'T') {
      strncpy(starting_address, record + 2, 6);
      recordpointer = 12;
      writeToOutputFile();
    }

    fgets(record, 100, iptr);
  }

  fclose(iptr);
  fclose(outptr);
  printf("The absolute loader has been executed, successfully.\n");
  return 0;
}