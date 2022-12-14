#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmValidation.h"
#include "pgmValidationWrite.h"
#include "pgmWrite.h"
#include "pgmTile.h"
#define max 50

int main(int argc, char **argv)
	{ /* main() */
	/* check for correct number of arguments */
	 if (argc == 1)
	 	{ /* no arguments passed */
	 	/* print an error message        */
     printf("Usage: ./pgmTile inputImage.pgm tiling_factor outputImage_<row>_<column>.pgm\n");
	 	/* and return an error code      */
	 	return 0;
		// Wrong arg count
	} else if (argc != 4){
		printf("ERROR: Bad Argument Count\n");
		return EXIT_WRONG_ARG_COUNT;
	}
	//intialize image pointer
    File *image = malloc(sizeof(File));
		// Converting factor passed into an integer
		int factor = atoi(argv[2]);
		// Check if factor is negative
		if(factor <= 0){
			printf("ERROR: Miscellaneous (Reduction factor not valid)\n");
			return 100;
		 }
    pgmTile(argv[0], argv[1], factor, argv[3], image);
		printf("TILED\n");
		return EXIT_NO_ERRORS;
}

int pgmTile(char *convert, char *input, int factor, char *output, File *image){
	// Reading image and returning value if not equal to 0
	readFile(input, image);
	// Create a 2d array holding image data
	unsigned char imageData[image->height][image->width];
	unsigned char *nextGrayValue = image->imageData;
	for(int row = 0; row < image->height; row++){
		for(int col = 0; col < image->width; col++){
			imageData[row][col] = *nextGrayValue;
			nextGrayValue++;
		}
	}
	 // Subract 19 to only get the filename without template
		int length = strlen(output) - 19;
		checkTemplate(output, length);
		char outputTile[length + 1];
	  strncpy(outputTile, output, length);
	  outputTile[length] = '\0';
	// Store original height in Variables
	int originalheight = image->height;
	int originalwidth = image->width;
	// Number of rows and cols in tiled image
	int numRows = originalheight / factor;
	int numCols = originalwidth / factor;
	// Set it to image struct
	image->height = numRows;
	image->width = numCols;
	nImageBytes = image->height * image->width * sizeof(unsigned char);
	// intialize row and column to start at
	int row = 0, col = 0;
	// Loop to make factor^2 images
	for (int newrow = 0; newrow < factor; newrow++){
	for (int newcol = 0; newcol < factor; newcol++) {
		// Allocate memory to imageData for tiled image
		image->imageData = (unsigned char *) malloc(nImageBytes);
		unsigned char *nextGrayValue = image->imageData;
		// Loop through imageData 2d array
		for (int x = row; x < row + numRows; x++){
			for(int y = col; y < col + numCols; y++){
			 *nextGrayValue = imageData[x][y];
			 nextGrayValue++;
			    }
		}
		// outputTileTemplate will keep changing using snprintf
		char outputTileTemplate[strlen(outputTile) + 19];
		snprintf(outputTileTemplate, strlen(outputTile) + 19, "%s_%d_%d.pgm", outputTile, newrow, newcol);
	 	write("./pgmEcho", image, outputTileTemplate);
		// Set imageData back to NULL for new tiled image
		image->imageData = NULL;
		free(image->imageData);
		col = col + numCols;
		if (col == originalwidth){
			row = row + numRows;
			col = 0;
		}
	 }
	}
return EXIT_NO_ERRORS;
}
