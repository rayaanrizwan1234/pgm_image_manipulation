#include <stdio.h>
#include <stdlib.h>
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmEchoStructs.h"
#include "pgmWrite.h"
#include "string.h"
#include "pgma2b.h"


int main(int argc, char **argv)

	{ /* main() */
	/* check for correct number of arguments */
	if (argc == 1)
		{ /* wrong arg count */
		/* print an error message        */
    printf("Usage: ./pgma2b inputImage.pgm outputImage.pgm");
		/* and return an error code      */
		return 0;
	}  else if (argc != 3){
		return EXIT_WRONG_ARG_COUNT;
	}/* wrong arg count */
		// Pointer to struct
		File *image = malloc(sizeof(File));
		pgma2b(argv[1], image, argv[2]);
		printf("CONVERTED\n");
} /* main() */

int pgma2b(char *input1,File *image, char *outputFile){
		// Reads in the inputFile
    readFile(input1, image);
		write("./pgma2b", image, outputFile);
    return 0;
}
