#include "SearchAndCount.h"
#include <string.h>
#include "ReadLine.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int searchAndCountWordInLine(char *wordToFind, char *line) {
  int count = 0;
  int wordIndex = 0;
  
  for(int lineIndex = 0; lineIndex < strlen(line); lineIndex++) {
    if(tolower(line[lineIndex]) == tolower(wordToFind[wordIndex])) {
      wordIndex++;
      if(wordIndex == strlen(wordToFind)) {
        count++;
        wordIndex = 0;
      }
    }else {
      wordIndex = 0;
    }
  }
  return count;
}

int searchAndCountWordInLines(char *wordToFind, char* filename, int freeMemorySel) {
  int i; 
  int count = 0;
  char **lines = readLines(filename);

  //lines[0] <=== accessing the first line
  for(i = 0; lines[i] != NULL; i++) {
    count += searchAndCountWordInLine(wordToFind, lines[i]);
  }
  if(freeMemorySel)
    free(lines);
  return count;
}