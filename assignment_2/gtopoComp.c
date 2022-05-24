#include <stdio.h>
/* library for memory routines     */
#include <stdlib.h>
#include "gtopoDef.h"
#include "gtopoRead.h"
#include "gtopoEchoStructs.h"
#include "gtopoWrite.h"
#include <string.h>


int main(int argc, char **argv)
	{ /* main() */
	/* check for correct number of arguments */
	if (argc == 1)
		{ /* wrong arg count */
		/* print an error message        */
		printf("Usage: %s firstFile width height secondFile", argv[0]);
		/* and return an error code      */
		return 0;
	} else if (argc != 5){
		printf("ERROR: Bad Argument Count");
		return EXIT_WRONG_ARG_COUNT;
	}
		//Create Pointer to Struct File
		int width = atoi(argv[2]);
		int height = atoi(argv[3]);
		// Call readFile and write
    File *image1 = malloc(sizeof(File));
    File *image2 = malloc(sizeof(File));
		Compare(argv[1], argv[4], width, height, image1, image2);
		return EXIT_NO_ERRORS;
}

int Compare(char *input1, char *input2, int width, int height, File *image1, File *image2){
  // Reads 1st file
  readFile(input1, width, height, image1);

    // Reads 2nd file
  readFile(input2, width, height, image2);

    // Conditions to check if File attributes are equal
  if (
      image1->width == image2->width &&
      image1->height == image2->height
    )
    {
      // Pointer to imageData
      unsigned char *nextGrayValue2 = image2->imageData;
      for(unsigned char *nextGrayValue1 = image1->imageData; nextGrayValue1 < image1->imageData + nImageBytes;nextGrayValue1++){
        // Read throught each image bit times by the maxGray and compare them to see if equal
        if((*nextGrayValue1) != (*nextGrayValue2)){
          printf("DIFFERENT");
          return EXIT_NO_ERRORS;
        }
        nextGrayValue2++;
      }
      printf("IDENTICAL");
     return EXIT_NO_ERRORS;
    }
    printf("DIFFERENT");
    return EXIT_NO_ERRORS;

}
