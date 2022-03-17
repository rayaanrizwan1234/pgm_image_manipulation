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
checkInput(inputFile);
// reads in Magic Number from file. Determines file type
image->magic_number[0] = getc(inputFile);
image->magic_number[1] = getc(inputFile);
printf("%u\n", image->magic_number[1]);

// scans for white spaces in the image logic
int scanCount = fscanf(inputFile, " ");
// scans for the white spaces if present in the code
char nextChar = fgetc(inputFile);
// Checks for comment lines in the file
checkComment( nextChar, image, inputFile);
// reads in the width, height and max gray values skipping white spaces
scanCount = fscanf(inputFile, "%u %u %u", &(image->width), &(image->height), &(image->maxGray));
// Checks the size and the gray values
checkDimensions(image->width, image->height, image->maxGray,image,inputFile, scanCount);
// allocate the data pointer
nImageBytes = image->width * image->height * sizeof(unsigned char);
image->imageData = (unsigned char *) malloc(nImageBytes);
// Checks the memory allocation
checkImageData(image->imageData, image, inputFile);

if(image->magic_number[1] == 50){
  for(unsigned char *nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes;nextGrayValue++){
    int grayValue = -1;
    int scanCount = fscanf(inputFile, "%u", &grayValue);
    // Checks the scan count and the gray value
    checkGrayValue(scanCount, grayValue,image,inputFile);
    *nextGrayValue = (unsigned char) grayValue;
  }
} else {
  int grayValue = -1;
 scanCount = fscanf(inputFile, "%u", &grayValue);
  fread(image->imageData, sizeof(unsigned char), nImageBytes, inputFile);
}
// pointer for efficient reading of the file

// close the file, no longer needed
fclose(inputFile);

return EXIT_NO_ERRORS;
}
