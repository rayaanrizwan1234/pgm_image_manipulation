#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmWrite.h"
#include "pgmValidationWrite.h"
#include "pgmValidation.h"
#include <string.h>
int write(char *convert, File *image, char *input) {
	// opens the file
	FILE *outputFile = fopen(input, "w");
  unsigned char *nextGrayValue = NULL;
	long nImageBytes =image->width * image->height * sizeof(unsigned char);
	// check whether file opening worked
	checkInput(outputFile);

	if(strcmp(convert, "./pgma2b") == 0){
				size_t nBytesWritten = fprintf(outputFile, "P5\n%d %d\n%d\n", image->width, image->height, image->maxGray);

				// checkDimensions( image->width,  image->height,  image->maxGray, image, outputFile, scanCount);		// pointer for efficient write code
		for (nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
		{
			fwrite(nextGrayValue, 1, 1, outputFile);
			// checkDimensions( image->width,  image->height,  image->maxGray, image, outputFile, scanCount);
			}
			  return EXIT_NO_ERRORS;
		// else statement to allow for use with different functions
	} else if(strcmp(convert, "./pgmb2a") == 0 || strcmp(convert, "./pgmReduce") == 0){
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
		} else if (strcmp(convert, "./pgmEcho") == 0){
			if(image->magic_number[1] == 50){
				size_t nBytesWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", image->width, image->height, image->maxGray);

				// pointer for efficient write code
				for (unsigned char *nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
				{
					int nextCol = (nextGrayValue - image->imageData + 1) % image->width;
					fprintf(outputFile, "%d%c", *nextGrayValue, (nextCol ? ' ' : '\n') );
					// checkDimensions( image->width,  image->height,  image->maxGray, image, outputFile, scanCount);
					}
					return EXIT_NO_ERRORS;
			} else {
				size_t nBytesWritten = fprintf(outputFile, "P5\n%d %d\n%d\n", image->width, image->height, image->maxGray);

				// checkDimensions( image->width,  image->height,  image->maxGray, image, outputFile, scanCount);		// pointer for efficient write code
		for (nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
		{
			fwrite(nextGrayValue, 1, 1, outputFile);
			// checkDimensions( image->width,  image->height,  image->maxGray, image, outputFile, scanCount);
			}
			  return EXIT_NO_ERRORS;
			}
		}
		return EXIT_BAD_INPUT_FILE;
}
