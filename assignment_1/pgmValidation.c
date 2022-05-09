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
    exit(BAD_FILE_NAME);
  }
  return 0;
}

int checkMagicNumber(File *image, char *input){
  if( image->magic_number[0] != 'P' || (image->magic_number[1] != '2' && image->magic_number[1] != '5')){
    printf("ERROR: Bad Magic Number (%s)", input);
    exit(BAD_MAGIC_NUMBER);
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
              exit(BAD_COMMENT_LINE);
              }
          if(strlen(commentString) >= 128){
            printf("ERROR: Bad Comment Line (%s)", input);
            exit(BAD_COMMENT_LINE);
            }
      }
  else {
          ungetc(nextChar, inputFile);
      }
      return 0;
}

int checkDimensions(File *image, FILE *inputFile, int scanCount, char *input){

  if(
    (scanCount != 3)||
    (image->width  < MIN_IMAGE_DIMENSION    )||
    (image->width  >= MAX_IMAGE_DIMENSION    )||
    (image->height < MIN_IMAGE_DIMENSION )||
    (image->height >= MAX_IMAGE_DIMENSION )
    )
    {
      free(image->commentLine);
      fclose(inputFile);
      printf("ERROR: Bad Dimensions (%s)", input);
      exit(BAD_DIMENSIONS);
  }
  return 0;
}

int checkMaxGray(File *image, FILE *inputFile, char *input){
  if (image->maxGray != 255 ){
    free(image->commentLine);
    fclose(inputFile);
    printf("ERROR: Bad Max Gray Value (%s)", input);
    exit(BAD_MAX_GRAY_VALUE);
  }
  return EXIT_NO_ERRORS;
}

int checkLittleData(int scanCount, int grayValue, File *image, FILE *inputFile, char *input){
  if((scanCount != 1) || (grayValue < 0) || (grayValue > 255))
  {
      free(image->commentLine);
      free(image->imageData);
      fclose(inputFile);
      printf("ERROR: Bad Data (%s)", input);
      exit(BAD_DATA);
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

int checkTemplate(char *output){
char *ext = "<row>_<column>.pgm";
char *extension = NULL;

if(!(strchr(output, '_'))){
printf("ERROR: Miscellaneous (%s)", output);
return MISCELLANEOUS;
}
const char *dot = strchr(output, '_');
if(!dot || dot == output) extension = "";
extension = dot + 1;
if(strcmp(extension, ext) != 0){
printf("ERROR: Miscellaneous (%s)", output);
exit(MISCELLANEOUS);
}
return EXIT_NO_ERRORS;
}
