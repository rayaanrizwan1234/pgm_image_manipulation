#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmWrite.h"
#include "pgmValidationWrite.h"
#include <string.h>
int write(char *convert, File *image, char *input) {
	FILE *outputFile = fopen(input, "w");
	  unsigned char *nextGrayValue = NULL;
	    long nImageBytes =image->width * image->height * sizeof(unsigned char);
	    // check whether file opening worked
	    // checkFileInput(image, outputFile, input);

	    if(strcmp(convert, "./pgm2b") == 0){
	        size_t nBytesWritten = fprintf(outputFile, "P5\n%d %d\n%d\n", image->width, image->height, image->maxGray);
	                printf("%zu\n", nBytesWritten);
	        // checkDimensions(image, nBytesWritten, outputFile);
	        // pointer for efficient write code
	        for (nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
	        {
	            fwrite(nextGrayValue, 1, 1, outputFile);
	            // checkDimensions(image, nBytesWritten, inputFile);
	            }
	              return EXIT_NO_ERRORS;
	    } else if(strcmp(convert, "./pgmb2a") == 0|| strcmp(convert, "./pgmEcho") == 0){
	        // write magic number, size & gray value
	        size_t nBytesWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", image->width, image->height, image->maxGray);
					printf("%zu\n", nBytesWritten);
	        // checkDimensions(image, nBytesWritten, outputFile);
	        // pointer for efficient write code
	        for (nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
	        {
	            int nextCol = (nextGrayValue - image->imageData + 1) % image->width;
	            fprintf(outputFile, "%d%c", *nextGrayValue, (nextCol ? ' ' : '\n') );
	            // checkDimensions(image, nBytesWritten, input);
	            }
	            return EXIT_NO_ERRORS;
	        }
	        return EXIT_BAD_INPUT_FILE;
}
