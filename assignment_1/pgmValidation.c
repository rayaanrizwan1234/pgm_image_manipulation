#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmRead.h"

// Check if inputfile exists
int checkInput(FILE *inputfile){
  if(inputfile == NULL){
    return EXIT_BAD_INPUT_FILE;
  }
  return 0;
}

int checkComment(char nextChar, File *image, FILE *inputFile){
  if(nextChar == '#')
      {
          image->commentLine = (char *) malloc (MAX_COMMENT_LINE_LENGTH);
          char *commentString = fgets(image->commentLine, MAX_COMMENT_LINE_LENGTH, inputFile);
          if(commentString == NULL){
              free(image->commentLine);
              fclose(inputFile);
              printf("Error: Reading pgm file -->  Check for Comment line");
              return EXIT_BAD_INPUT_FILE;
              }
      }
  else
      {
          ungetc(nextChar, inputFile);
      }
      return 0;
}

int checkDimensions(int width, int height, int maxGray, File *image, FILE *inputFile, int scanCount){
  if(
    (scanCount != 3)||
    (image->width  < MIN_IMAGE_DIMENSION    )||
    (image->width  > MAX_IMAGE_DIMENSION    )||
    (image->height < MIN_IMAGE_DIMENSION )||
    (image->height > MAX_IMAGE_DIMENSION )||
    (image->maxGray != 255        )
    )
    {
      free(image->commentLine);
      fclose(inputFile);
      printf("Error: Reading pgm file");
      return EXIT_BAD_INPUT_FILE;
  }
  return 0;
}

int checkImageData(unsigned char *imageData, File *image, FILE *inputFile){
  if (image->imageData == NULL){
      free(image->commentLine);
      fclose(inputFile);
      printf("Error: failed");
      return EXIT_BAD_INPUT_FILE;
    }
    return 0;
}

int checkGrayValue(int scanCount, int grayValue, File *image, FILE *inputFile){
  if((scanCount != 1) || (grayValue < 0) || (grayValue > 255))
  {
      free(image->commentLine);
      free(image->imageData);
      fclose(inputFile);
      printf("Error: Failes 3");
      return EXIT_BAD_INPUT_FILE;
  }
  return 0;
}
