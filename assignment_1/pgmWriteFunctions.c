#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmWrite.h"
#include "pgmValidationWrite.h"
#include "pgmValidation.h"
#include "pgmWriteFunctions.h"
#include <string.h>

int writeBinary(FILE *outputFile, File *image, unsigned char *nextGrayValue, long nImageBytes){
  size_t nBytesWritten = fprintf(outputFile, "P5\n%d %d\n%d\n", image->width, image->height, image->maxGray);

  // checkDimensions( image->width,  image->height,  image->maxGray, image, outputFile, scanCount);		// pointer for efficient write code
for (nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
{
fwrite(nextGrayValue, 1, 1, outputFile);
// checkDimensions( image->width,  image->height,  image->maxGray, image, outputFile, scanCount);
}
  return EXIT_NO_ERRORS;
}

int writeAscii(FILE *outputFile, File *image, unsigned char *nextGrayValue, long nImageBytes){
  // write magic number, size & gray value
  size_t nBytesWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", image->width, image->height, image->maxGray);

  // pointer for efficient write code
  for (unsigned char *nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
  {
    int nextCol = (nextGrayValue - image->imageData + 1) % image->width;
    fprintf(outputFile, "%d%c", *nextGrayValue, (nextCol ? ' ' : '\n') );
    // checkDimensions( image->width,  image->height,  image->maxGray, image, outputFile, scanCount);
    }
    return EXIT_NO_ERRORS;
}
