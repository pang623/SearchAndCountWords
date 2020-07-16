#include "ReadLine.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char **readLines(char *fileName) {
  char **lines = malloc(sizeof(char *) * 1024);
  char buffer[1024];
  int i = 0;
  FILE *fileHandler;
  
  fileHandler = fopen(fileName, "r");
  if(fileHandler == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  while (fgets(buffer, 1024, fileHandler) != NULL) {
    lines[i] = strdup(buffer);
    i++;
    }
  
  return lines;
}
