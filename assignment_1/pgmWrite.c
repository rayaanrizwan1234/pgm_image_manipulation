#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmWrite.h"
#include "pgmValidationWrite.h"
#include "pgmValidation.h"
#include "pgmWriteFunctions.h"
#include <string.h>
int write(char *convert, File *image, char *input) {
	// if(fileExtension(image, input) != 0){
	// 	return OUTPUT_FAILED;
	// }
	// opens the file
	FILE *outputFile = fopen(input, "w");
  unsigned char *nextGrayValue = NULL;
	long nImageBytes = image->width * image->height * sizeof(unsigned char);
	// check whether file opening worked
	if(checkFile(outputFile, image, input) != 0){
		return OUTPUT_FAILED;
	}
	if(strcmp(convert, "./pgma2b") == 0){
			 writeBinary(outputFile, image, nextGrayValue, nImageBytes);
			 fclose(outputFile);
			 return 0;
		// else statement to allow for use with different functions
	} else if(strcmp(convert, "./pgmb2a") == 0 || strcmp(convert, "./pgmReduce") == 0){
			writeAscii(outputFile, image, nextGrayValue, nImageBytes);
			fclose(outputFile);
			return 0;
		} else if (strcmp(convert, "./pgmEcho") == 0){
			if(image->magic_number[1] == 50){
				writeAscii(outputFile, image, nextGrayValue, nImageBytes);
				fclose(outputFile);
				return 0;
			} else {
				writeBinary(outputFile, image, nextGrayValue, nImageBytes);
				fclose(outputFile);
				return 0;
		}
}
return OUTPUT_FAILED;

// FILE *out = fopen(input, "w");
// 	  unsigned char *nextGrayValue = NULL;
// 	    long nImageBytes =image->width * image->height * sizeof(unsigned char);
//       //file opening tested
//
// 	    if(strcmp(convert, "./pgm2b") == 0){
// 	        size_t nBytesWritten = fprintf(out, "P5\n%d %d\n%d\n", image->width, image->height, image->maxGray);
// 	        // nBytesWrittenChecker(nBytesWritten, image);
//
// 	        // pointer for efficient write code
// 	        for (nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
// 	        {
// 	            fwrite(nextGrayValue, 1, 1, out);
//               //dimensionsCheck()
// 	            }
// 	              return EXIT_NO_ERRORS;
// 	    } else if(strcmp(convert, "./pgmb2a") == 0|| strcmp(convert, "./pgmEcho") == 0 || strcmp(convert, "./pgmReduce") == 0){
// 	        // must be writing magic number, size & gray value
// 	        size_t nBytesWritten = fprintf(out, "P2\n%d %d\n%d\n", image->width, image->height, image->maxGray);
//           // nBytesWrittenChecker(nBytesWritten, image);
//
// 	        // pointer for efficient write code
// 	        for (nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
// 	        {
// 	            int nextCol = (nextGrayValue - image->imageData + 1) % image->width;
// 	            fprintf(out, "%d%c", *nextGrayValue, (nextCol ? ' ' : '\n') );
//               //dimensionsCheck()
// 	            }
// 	            return EXIT_NO_ERRORS;
// 	        }
// 	        return EXIT_BAD_INPUT_FILE;
}
