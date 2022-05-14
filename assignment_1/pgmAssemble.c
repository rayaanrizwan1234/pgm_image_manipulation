#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmValidation.h"
#include "pgmWrite.h"
#include "pgmValidationWrite.h"

int main(int argc, char **argv)
	{ /* main() */
	/* check for correct number of arguments */
	 if (argc == 1)
	 	{ /* no arguments passed */
	 	/* print an error message        */
     printf("Usage: ./pgmAssemble outputImage.pgm width height (row column inputImage.pgm)+\n");
	 	/* and return an error code      */
	 	return 0;
		// Wrong arg count
	} if (argc % 3 != 1){
		printf("ERROR: Bad Argument Count\n");
		return EXIT_WRONG_ARG_COUNT;
	}

    int nOfImages = (argc-4)/3;
    int outputWidth = atoi(argv[2]);
    int outputHeight = atoi(argv[3]);
		unsigned char magic_number = NULL;
		// 2d Array to store all daat from input images
    unsigned char outputData[outputHeight][outputWidth];
    for(int i = 0; i < nOfImages; i++){
			//intialize image pointer
      File *image = malloc(sizeof(File));
			//Get input file name
      int imagenumber = 6 + (3 * i);
      readFile(argv[imagenumber], image);
			magic_number = image->magic_number[1];
			// assigns start row and col to variables
      int argument = 4 + (3*i);
      int startRow = atoi(argv[argument]);
      int startCol = atoi(argv[argument+1]);
			//Gets image data
      unsigned char *nextGrayValue = image->imageData;
			// Puts the data into the desired row and column
      for(int row = startRow; row < image->height + startRow; row++){
        for(int col = startCol; col < image->width + startCol; col++){
          outputData[row][col] = *nextGrayValue;
          nextGrayValue++;
        }
      }
    }
		//Initialise image pointer for writing
    File *image = malloc(sizeof(File));
		image->magic_number[1] = magic_number;
    image->width = outputWidth;
    image->height = outputHeight;
		image->maxGray = 255;
    nImageBytes = image->height * image->width * sizeof(unsigned char);
    image->imageData = (unsigned char *) malloc(nImageBytes);
    unsigned char *nextGrayValue = image->imageData;
    for(int row = 0; row < outputHeight; row ++){
      for(int col = 0; col < outputWidth; col++){
        *nextGrayValue = outputData[row][col];
        nextGrayValue++;
      }
    }
    write("./pgmEcho", image, argv[1]);
		printf("ASSEMBLED\n");
		return EXIT_NO_ERRORS;
}
