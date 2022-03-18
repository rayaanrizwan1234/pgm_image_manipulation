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
	 if (argc != 4)
	 	{ /* wrong arg count */
	 	/* print an error message        */
     printf("Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm");
	 	/* and return an error code      */
	 	return EXIT_WRONG_ARG_COUNT;
   }
    File *image = malloc(sizeof(File));
		int factor = atoi(argv[2]);
    pgmReduce(argv[0], argv[1], factor, argv[3], image);
		printf("REDUCED\n");
  return 0;
}

int pgmReduce(char *convert, char *input, int factor, char *output, File *image){
image->magic_number[0] = '0';
image->magic_number[1] = '0';
image->commentLine = NULL;
image->width = 0;
image->height = 0;
image->maxGray = 255;
image->imageData = NULL;
FILE *inputFile = fopen(input, "r");
image->magic_number[0] = getc(inputFile);
image->magic_number[1] = getc(inputFile);
int scanCount = fscanf(inputFile, " ");
printf("%d\n", scanCount);
char nextChar = fgetc(inputFile);
checkComment( nextChar, image, inputFile);
scanCount = fscanf(inputFile, "%u %u %u", &(image->width), &(image->height), &(image->maxGray));
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
			checkGrayValue(scanCount, grayValue,image,inputFile);
			imageData[row][col] = (unsigned char) grayValue;
		}
	}

free(image->imageData);
image->width = width;
image->height = height;
image->imageData = (unsigned char *) malloc(nImageBytes);
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
write(convert, image, output);
return EXIT_NO_ERRORS;
}
