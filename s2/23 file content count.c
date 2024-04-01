#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 100
#define MAX_WORD_LENGTH 100

int main() {
  FILE *inputFile, *outputFile;
  char inputFileName[MAX_FILE_NAME];
  char outputFileName[MAX_FILE_NAME];
  char ch;
  int charCount = 0, wordCount = 0, lineCount = 0, inWord = 0;

  // Prompt user for input and output file names
  printf("Enter input file name: ");
  scanf("%s", inputFileName);
  printf("Enter output file name: ");
  scanf("%s", outputFileName);

  // Open input file
  inputFile = fopen(inputFileName, "r");
  if (inputFile == NULL) {
    printf("Error opening input file.\n");
    exit(1);
  }

  // Open output file
  outputFile = fopen(outputFileName, "w");
  if (outputFile == NULL) {
    printf("Error opening output file.\n");
    fclose(inputFile);
    exit(1);
  }

  // Read characters from input file and count characters, words, and lines
  while ((ch = fgetc(inputFile)) != EOF) {
    charCount++;

    // Count words
    if (isspace(ch)) {
      inWord = 0;
    } else if (!inWord) {
      inWord = 1;
      wordCount++;
    }

    // Count lines
    if (ch == '\n') {
      lineCount++;
    }
  }

  // Increment line count if the file doesn't end with a newline
  if (charCount > 0 && ch != '\n') {
    lineCount++;
  }

  // Write results to output file
  fprintf(outputFile, "Number of characters: %d\n", charCount);
  fprintf(outputFile, "Number of words: %d\n", wordCount);
  fprintf(outputFile, "Number of lines: %d\n", lineCount);

  // Close files
  fclose(inputFile);
  fclose(outputFile);

  printf("Operation completed successfully. Results written to %s.\n",
         outputFileName);

  return 0;
}
