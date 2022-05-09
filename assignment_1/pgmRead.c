#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmValidation.h"


int readFile (char *input, File *image) {
image->magic_number[0] = '0';
image->magic_number[1] = '0';
image->magic_Number = NULL;
image->commentLine = NULL;
image->width = 0;
image->height = 0;
image->maxGray = 255;
image->imageData = NULL;

// reading in the data
FILE *inputFile = fopen(input, "r");
// fails to read in file, returns error from pgmDef.h
// Checks the file being inputted
if (checkInput(inputFile, input) != 0){
  return EXIT_BAD_INPUT_FILE;
}

// reads in Magic Number from file. Determines file type
image->magic_number[0] = getc(inputFile);
image->magic_number[1] = getc(inputFile);

if(checkMagicNumber(image, input) != 0){
  return BAD_MAGIC_NUMBER;
}

// scans for white spaces in the image logic
int scanCount = fscanf(inputFile, " ");
// scans for the white spaces if present in the code
char nextChar = fgetc(inputFile);
// Checks for comment lines in the file
 if (checkComment( nextChar, image, inputFile, input) != 0){
   return BAD_COMMENT_LINE;
 }
// reads in the width, height and max gray values skipping white spaces
scanCount = fscanf(inputFile, "%u %u %u", &(image->width), &(image->height), &(image->maxGray));
// Checks the size and the gray values
if(checkDimensions(image,inputFile, scanCount, input) != 0){
    return BAD_DIMENSIONS;
}
if(checkMaxGray(image,inputFile, input) != 0){
    return BAD_MAX_GRAY_VALUE;
}

// allocate the data pointer
nImageBytes = image->width * image->height * sizeof(unsigned char);
image->imageData = (unsigned char *) malloc(nImageBytes);

// Checks the memory allocation
if(checkImageMemory(image) != 0){
  return IMAGE_MEMORY_FAIL;
}

if(image->magic_number[1] == 50){

  for(unsigned char *nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes;nextGrayValue++){
    int grayValue = -1;
    int scanCount = fscanf(inputFile, "%u", &grayValue);
    // Checks the scan count and the gray value
    if(checkLittleData(scanCount, grayValue, image, inputFile, input) != 0){
     return BAD_DATA;
    }
    *nextGrayValue = (unsigned char) grayValue;
  }

} else {
  int grayValue = -1;
 scanCount = fscanf(inputFile, "%u", &grayValue);
  fread(image->imageData, sizeof(unsigned char), nImageBytes, inputFile);
  // unsigned char *nextGrayValue = image->imageData;
  // for(int x = 0; x < image->height; x++){
  //   for(int y = 0; y < image->width; y++){
  //     if(*nextGrayValue < 0 || *nextGrayValue > 255){
  //       free(image->commentLine);
  //       free(image->imageData);
  //       fclose(inputFile);
  //       printf("ERROR: Bad Data (%s)", input);
  //       return BAD_DATA;
  //     }
  //     nextGrayValue++;
  //   }
  //

}
// pointer for efficient reading of the file
if (checkTooMuchData(image, inputFile, input) != 0){
  return BAD_DATA;
}
// close the file, no longer needed
fclose(inputFile);

return EXIT_NO_ERRORS;
}
