#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmValidation.h"
#include "pgmWrite.h"
#include "pgmReduce.h"


int main(int argc, char **argv)
	{ /* main() */
	/* check for correct number of arguments */
	 if (argc == 1)
	 	{ /* wrong arg count */
	 	/* print an error message        */
     printf("Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm");
	 	/* and return an error code      */
	 	return 0;
	} else if (argc != 4){
		printf("ERROR: Bad Argument Count");
		return EXIT_WRONG_ARG_COUNT;
	}
    File *image = malloc(sizeof(File));
		int factor = atoi(argv[2]);

		if(factor < 0){
			printf("ERROR: Miscellaneous (Reduction factor is negative)");
			return 100;
		 }
		// if(isdigit(factor) == 0){
		// 	printf("ERROR: Miscellaneous (non-numeric scaling factor)");
		// 	return 100;
		// }
    int returnReduce = pgmReduce(argv[0], argv[1], factor, argv[3], image);
		if(returnReduce == 0){
			printf("REDUCED");
			return EXIT_NO_ERRORS;
		}
  return returnReduce;
}

int pgmReduce(char *convert, char *input, int factor, char *output, File *image){
	// Intialize variables to NULL
image->magic_number[0] = '0';
image->magic_number[1] = '0';
image->commentLine = NULL;
image->width = 0;
image->height = 0;
image->maxGray = 255;
image->imageData = NULL;
// Open file for reading
FILE *inputFile = fopen(input, "r");
// Check if file is valid
if (checkInput(inputFile, input) != 0){
return BAD_FILE_NAME;
}

image->magic_number[0] = getc(inputFile);
image->magic_number[1] = getc(inputFile);
// Validates if magic number is either 50 or 53 i.e ASCII or Bianry
if(checkMagicNumber(image, input) != 0){
return BAD_MAGIC_NUMBER;
}

// scans for white spaces in the image logic
int scanCount = fscanf(inputFile, " ");
// scans for the white spaces if present in the code
char nextChar = fgetc(inputFile);

// Checks for comment lines in the file
if (checkComment( nextChar, image, inputFile) != 0){
return BAD_COMMENT_LINE;
}
scanCount = fscanf(inputFile, "%u %u %u", &(image->width), &(image->height), &(image->maxGray));
// Checks the size and the gray values
if(checkDimensions(image,inputFile, scanCount, input) != 0){
	return BAD_DIMENSIONS;
}
//unsigned char *grayValue = image->imageData;
unsigned char imageData[image->height][image->width];
int height = 0, width = 0;
for(int row = 0; row < image->height; row ++){
	if(row % factor == 0){
		height++;
	}
	 width = 0;
	for(int col = 0; col < image->width; col++){
		// unsigned char *nextGrayValue = 0;
		if(col % factor == 0){
			width++;
		}
		int grayValue = -1;
		int scanCount = fscanf(inputFile, "%u", &grayValue);
		// Checks the scan count and the gray value
		if(checkLittleData(scanCount, grayValue, image, inputFile, input) != 0){
      return BAD_DATA;
    }
		imageData[row][col] = (unsigned char) grayValue;
	}
}
if (checkTooMuchData(image, inputFile, input) != 0){
	return BAD_DATA;
}

free(image->imageData);
image->imageData = (unsigned char *) malloc(nImageBytes);

if(checkImageMemory(image) != 0){
return IMAGE_MEMORY_FAIL;
}

nImageBytes = height * width * sizeof(unsigned char);
unsigned char *nextGrayValue = image->imageData;
for(int row = 0; row < image->height; row++){
for(int col = 0; col < image->width; col++){
	if(row % factor == 0 && col % factor == 0){
		*nextGrayValue = imageData[row][col];
		nextGrayValue++;
	}
}
}
image->width = width;
image->height = height;
int returnWrite = write(convert, image, output);
if(returnWrite != 0){
return returnWrite;
}
return EXIT_NO_ERRORS;
}
