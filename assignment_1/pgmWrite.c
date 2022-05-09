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
	checkFile(outputFile, image, input);
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
}
