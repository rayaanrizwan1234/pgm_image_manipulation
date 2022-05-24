#include <stdlib.h>
#include <stdio.h>
#include "gtopoDef.h"
#include "gtopoRead.h"
#include "gtopoEchoStructs.h"
#include "gtopoWrite.h"
#include "gtopoReduce.h"


int main(int argc, char **argv)
	{ /* main() */
	/* check for correct number of arguments */
	 if (argc == 1)
	 	{ /* wrong arg count */
	 	/* print an error message        */
     printf("Usage: ./pgmReduce input width height reduction_factor output");
	 	/* and return an error code      */
	 	return 0;
	} else if (argc != 6){
		printf("ERROR: Bad Argument Count");
		return EXIT_WRONG_ARG_COUNT;
	}
		// Intiialize image pointer
    File *image = malloc(sizeof(File));
		int factor = atoi(argv[4]);
		// Check if factor is non-numeric or negative
		if(factor <= 0){
			printf("ERROR: Miscellaneous (Reduction factor is not valid)");
			return 100;
		 }
		 int width = atoi(argv[2]);
 		 int height = atoi(argv[3]);
    	Reduce(argv[0], argv[1], width, height, factor, argv[5], image);
			printf("REDUCED");
			return EXIT_NO_ERRORS;
}

int Reduce(char *convert, char *input, int widthdem, int heightdem, int factor, char *output, File *image){

 readFile(input, widthdem, heightdem, image);
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
