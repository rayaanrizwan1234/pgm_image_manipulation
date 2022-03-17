#include <stdio.h>
#include <stdlib.h>
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmEchoStructs.h"
#include "pgmWrite.h"
#include "string.h"
#include "pgma2b.h"


int pgma2b(char *input1,File *image, char *outputFile){
    readFile(input1, image);
    FILE *output = fopen(outputFile, "w");
    unsigned char *nextGrayValue = NULL;

    long nImageBytes = image->width * image->height * sizeof(unsigned char);
    // check whether file opening worked
    // checkInput(image, output, input1);

    // write magic number, size & gray value
    size_t nBytesWritten = fprintf(output, "P5\n%d %d\n%d\n", image->width, image->height, image->maxGray);
    printf("%zu\n",nBytesWritten);
    // checkDimensions(image, nBytesWritten, input1);

    // pointer for efficient write code
    for (nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes; nextGrayValue++)
    {
      // int nextCol = (nextGrayValue - image->imageData + 1) % image->width;
      // nBytesWritten = fprintf(outputFile, "%d%c", nextGrayValue, (nextCol ? ' ' : '\n'));
      fwrite(nextGrayValue, 1, 1, output);
      // checkDimensions(image, nBytesWritten, input1);
      }
  //  fwrite(image->imageData, sizeof(unsigned char), image->width * image->height, output);
   fclose(output);

    return 0;
}

int main(int argc, char **argv)

	{ /* main() */
	/* check for correct number of arguments */
	if (argc != 3)
		{ /* wrong arg count */
		/* print an error message        */
    printf("Usage: ./pgma2b inputImage.pgm outputImage.pgm");
		/* and return an error code      */
		return EXIT_WRONG_ARG_COUNT;
		} /* wrong arg count */
		File *image = malloc(sizeof(File));
		pgma2b(argv[1], image, argv[2]);
} /* main() */
