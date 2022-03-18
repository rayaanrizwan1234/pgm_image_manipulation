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
	// if (argc != 4)
	// 	{ /* wrong arg count */
	// 	/* print an error message        */
  //   printf("Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm");
	// 	/* and return an error code      */
	// 	return EXIT_WRONG_ARG_COUNT;
  // }
    File *image = malloc(sizeof(File));
    pgmReduce("./pgmReduce", "balloons.ascii.pgm", 20, "outReduce.pgm", image);
  return 0;
}

int pgmReduce(char *convert, char *input, int n, char *output, File *image){
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
int row = 0, col = 0;
//unsigned char *grayValue = image->imageData;
unsigned char imageData[image->height][image->width];
int h = 0, w = 0;
for(row = 0; row < image->height; row ++){
	if(row % n == 0){
		h++;
	}
	w = 0;
	for(col = 0; col < image->width; col++){
		// unsigned char *nextGrayValue = 0;
		if(col % n == 0){
			w++;
		}
		// imageData[row][col] = *(grayValue);
		// grayValue++;
		int grayValue = -1;
		int scanCount = fscanf(inputFile, "%u", &grayValue);
		// Checks the scan count and the gray value
		checkGrayValue(scanCount, grayValue,image,inputFile);
		imageData[row][col] = (unsigned char) grayValue;
	}
}

int height = image->height, width = image->width;
free(image->imageData);
image->width = w;
image->height = h;
nImageBytes = h * w * sizeof(unsigned char);
image->imageData = (unsigned char *) malloc(nImageBytes);

unsigned char *nextGrayValue = image->imageData;
for(int i = 0; i < height; i++){
	for(int j = 0; j < width; j++){
		if(i%n == 0 && j%n == 0){
			*nextGrayValue = imageData[i][j];
			nextGrayValue++;
		}
	}
}
write(convert, image, output);
  return 0;
}
