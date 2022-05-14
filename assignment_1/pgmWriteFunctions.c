#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmWrite.h"
#include "pgmValidationWrite.h"
#include "pgmValidation.h"
#include "pgmWriteFunctions.h"
#include <string.h>
// Writes a binary file
int writeBinary(FILE *outputFile, File *image, unsigned char *nextGrayValue, long nImageBytes){
  // write magic number, size & gray value
  size_t nBytesWritten = fprintf(outputFile, "P5\n%d %d\n%d\n", image->width, image->height, image->maxGray);
// Loop through imageData and writes it to a file
for (nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
{
fwrite(nextGrayValue, 1, 1, outputFile);
}
  return EXIT_NO_ERRORS;
}

int writeAscii(FILE *outputFile, File *image, unsigned char *nextGrayValue, long nImageBytes){
  // write magic number, size & gray value
  size_t nBytesWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", image->width, image->height, image->maxGray);

  // Loop through imageData and writes it to a file
  for (unsigned char *nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
  {
    int nextCol = (nextGrayValue - image->imageData + 1) % image->width;
    fprintf(outputFile, "%d%c", *nextGrayValue, (nextCol ? ' ' : '\n') );
    }
    return EXIT_NO_ERRORS;
}
