#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmRead.h"

// Check if inputfile exists
int checkInput(FILE *inputfile, char *input){
  char *extension = NULL;
  char *ext = "pgm";
  if(inputfile == NULL){
    printf("ERROR: Bad File Name (%s)", input);
    return BAD_FILE_NAME;
  }
  const char *dot = strchr(input, '.');
  if(!dot || dot == input) extension = "";
  extension = dot + 1;
  if (strcmp(extension, ext) != 0 ){
    printf("ERROR: Bad File Name (%s)", input);
    return BAD_FILE_NAME;
  }
  return 0;
}

int checkMagicNumber(File *image, char *input){
  if( image->magic_number[1] != 50 && image->magic_number[1] != 53){
    printf("ERROR: Bad Magic Number (%s)", input);
    return BAD_MAGIC_NUMBER;
  }
  return 0;
}

int checkComment(char nextChar, File *image, FILE *inputFile, char *input){
  if(nextChar == '#')
      {
          image->commentLine = (char *) malloc (MAX_COMMENT_LINE_LENGTH);
          char *commentString = fgets(image->commentLine, MAX_COMMENT_LINE_LENGTH, inputFile);
          if(commentString == NULL){
              free(image->commentLine);
              fclose(inputFile);
              printf("ERROR: Bad Comment Line (%s)", input);
              return BAD_COMMENT_LINE;
              }
      }
  else {
          ungetc(nextChar, inputFile);
      }
      return 0;
}

int checkDimensions(File *image, FILE *inputFile, int scanCount, char *input){
  int dimensions = image->width * image->height;
  if(
    (scanCount != 3)||
    dimensions < 1 ||
    dimensions >= 65536)
    {
      free(image->commentLine);
      fclose(inputFile);
      printf("ERROR: Bad Dimensions (%s)", input);
      return BAD_DIMENSIONS;
  }
  if (image->maxGray != 255 ){
    free(image->commentLine);
    fclose(inputFile);
    printf("ERROR: Bad Max Gray Value (%s)", input);
    return BAD_MAX_GRAY_VALUE;
  }
  return 0;
}

int checkLittleData(int scanCount, int grayValue, File *image, FILE *inputFile, char *input){
  if((scanCount != 1) || (grayValue < 0) || (grayValue > 255))
  {
      free(image->commentLine);
      free(image->imageData);
      fclose(inputFile);
      printf("ERROR: Bad Data (%s)", input);
      return BAD_DATA;
  }
  return 0;
}

int checkTooMuchData(File *image, FILE *inputFile, char *input){
    int grayValue = -1;
    int scanCount = fscanf(inputFile, "%u", &grayValue);
  if(grayValue != -1){
    free(image->commentLine);
    free(image->imageData);
    fclose(inputFile);
    printf("ERROR: Bad Data (%s)", input);
    return BAD_DATA;
  }
  return 0;
}

int checkImageMemory(File *image){
  if (image->imageData == NULL){
    printf("ERROR: Image Malloc Failed");
    return IMAGE_MEMORY_FAIL;
  }
  return 0;
}

int checkIfFileBinary(File *image, char *input){
if (image -> magic_number[1] == 53){
  return 0;
}
return 1;
}

int checkIfFileAscii(File *image, char *input){
if (image -> magic_number[1] == 50){
  return 0;
}
return 1;
}
