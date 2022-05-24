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
     printf("Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm\n");
	 	/* and return an error code      */
	 	return 0;
	} else if (argc != 4){
		printf("ERROR: Bad Argument Count\n");
		return EXIT_WRONG_ARG_COUNT;
	}
		// Intiialize image pointer
    File *image = malloc(sizeof(File));
		int factor = atoi(argv[2]);
		// Check if factor is non-numeric or negative
		if(factor <= 0){
			printf("ERROR: Miscellaneous (Reduction factor is not valid)\n");
			return 100;
		 }

    	pgmReduce(argv[0], argv[1], factor, argv[3], image);
			printf("REDUCED\n");
			return EXIT_NO_ERRORS;
}

int pgmReduce(char *convert, char *input, int factor, char *output, File *image){

 readFile(input, image);
	// Set image->imageData to a 2d array
	unsigned char *grayValue = image->imageData;
	unsigned char imageData[image->height][image->width];
	//Intiialize reduced image height and width
	int height = 0, width = 0;
	for(int row = 0; row < image->height; row ++){
		if(row % factor == 0){
			height++;
		}
	 width = 0;
	 for(int col = 0; col < image->width; col++){
				if(col % factor == 0){
					width++;
				}
				imageData[row][col] = *grayValue;
				grayValue++;
			}
	}
// Free old imageData
free(image->imageData);
image->imageData = (unsigned char *) malloc(nImageBytes);

checkImageMemory(image);

nImageBytes = height * width * sizeof(unsigned char);
//Initialize pointer to new imageData
unsigned char *nextGrayValue = image->imageData;
for(int row = 0; row < image->height; row++) {
	for(int col = 0; col < image->width; col++) {
		if(row % factor == 0 && col % factor == 0) {
			*nextGrayValue = imageData[row][col];
			nextGrayValue++;
		}
	}
	}
image->width = width;
image->height = height;

write("./pgmEcho", image, output);

return EXIT_NO_ERRORS;
}
