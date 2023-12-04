#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *iptr, *outptr;
char record[100];
char starting_address[100];
int recordpointer;

void writeToOutputFile() {
  char objectcode[20];
  int address;
  address = strtol(starting_address, NULL, 16);
  while (record[recordpointer] != '\0') {
    fprintf(outptr, "%x\t", address);
    strncpy(objectcode, record + (recordpointer), 6);
    fprintf(outptr, "%s\n", objectcode);
    recordpointer += 7;
    address += 3;
    if (record[recordpointer] == '^') {
      recordpointer++;
    }
  }
}

int main() {
  iptr = fopen("inputfile.txt", "r");
  outptr = fopen("outputfile.text", "w");

  if (iptr == NULL)
    printf("Kindly Enter a Valid File");

  fgets(record, sizeof(record) / sizeof(char), iptr);
  while (record[0] != 'E') {
    if (record[0] == 'T') {
      strncpy(starting_address, record + 2, 6);
      recordpointer = 12;
      writeToOutputFile();
    }

    fgets(record, sizeof(record) / sizeof(char), iptr);
  }

  fclose(iptr);
  fclose(outptr);
  printf("The absolute loader has been executed, successfully.");
  return 0;
}

/*
inputfile.txt

H^SAMPLE^001000^000035
T^001000^06^001003^071009
T^002000^03^111111
E^000000

outputfile.txt

1000	001003
1003	071009
2000	111111

*/
