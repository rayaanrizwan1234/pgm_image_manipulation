#include <stdlib.h>
#include <stdio.h>
#include "gtopoDef.h"
#include "gtopoRead.h"
#include "gtopoEchoStructs.h"
#include "gtopoWrite.h"

// Check if inputfile exists
int checkInput(FILE *inputfile, char *input){
  if(inputfile == NULL){
    printf("ERROR: Bad File Name (%s)", input);
    exit(BAD_FILE_NAME);
  }
  return 0;
}

int checkTooMuchData(File *image, FILE *inputFile, char *input){
    int grayValue = -1;
    int scanCount = fscanf(inputFile, "%u", &grayValue);
  if(grayValue != -1){
    free(image->imageData);
    fclose(inputFile);
    printf("ERROR: Bad Data (%s)", input);
    exit(BAD_DATA);
  }
  return 0;
}

int checkImageMemory(File *image){
  if (image->imageData == NULL){
    printf("ERROR: Image Malloc Failed");
    exit(IMAGE_MEMORY_FAIL);
  }
  return 0;
}
