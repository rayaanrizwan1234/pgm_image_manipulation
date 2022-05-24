#include <stdlib.h>
#include <stdio.h>
#include "gtopoEchoStructs.h"
#include "gtopoDef.h"
#include "gtopoWrite.h"
#include "gtopoValidationWrite.h"
#include "gtopoValidation.h"
#include "gtopoWriteFunctions.h"
#include <string.h>
int write(char *convert, File *image, char *input) {

		// opens the file
	FILE *outputFile = fopen(input, "w");
  unsigned char *nextGrayValue = NULL;
	long nImageBytes = image->width * image->height * sizeof(unsigned char);
	// check whether file opening worked
	checkFile(outputFile, image, input);

	writeBinary(outputFile, image, nextGrayValue, nImageBytes);
	fclose(outputFile);
	return 0;


exit(OUTPUT_FAILED);
}
