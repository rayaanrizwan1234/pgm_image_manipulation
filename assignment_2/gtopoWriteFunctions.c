#include <stdlib.h>
#include <stdio.h>
#include "gtopoEchoStructs.h"
#include "gtopoDef.h"
#include "gtopoWrite.h"
#include "gtopoValidationWrite.h"
#include "gtopoValidation.h"
#include "gtopoWriteFunctions.h"
#include <string.h>

int writeBinary(FILE *outputFile, File *image, unsigned char *nextGrayValue, long nImageBytes){
  // size_t nBytesWritten = fprintf(outputFile, "%d %d\n", image->width, image->height);
  int count = 0;
  // checkDimensions( image->width,  image->height,  image->maxGray, image, outputFile, scanCount);		// pointer for efficient write code
for (nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
{
int write = fwrite(nextGrayValue, 1, 1, outputFile);
count++;
}
  return EXIT_NO_ERRORS;
}
