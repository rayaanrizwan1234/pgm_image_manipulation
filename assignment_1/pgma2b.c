#include <stdio.h>
#include <stdlib.h>
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmEchoStructs.h"
#include "pgmWrite.h"
#include "string.h"
#include "pgma2b.h"
#include "pgmValidation.h"


int main(int argc, char **argv)

	{ /* main() */
	/* check for correct number of arguments */
	if (argc == 1)
		{ /* If no parameters were given */
		/* print an error message        */
    printf("Usage: ./pgma2b inputImage.pgm outputImage.pgm");
		/* and return an error code      */
		return 0;
	} else if (argc != 3){
		printf("ERROR: Bad Argument Count");
		return EXIT_WRONG_ARG_COUNT;
	}/* wrong arg count */
		// Pointer to struct
		File *image = malloc(sizeof(File));
		int Returnpgma2b = pgma2b(argv[1], image, argv[2]);
		if (Returnpgma2b == 0){
			printf("CONVERTED\n");
			return EXIT_NO_ERRORS;
		} else {
			return Returnpgma2b;
		}
} /* main() */

int pgma2b(char *input,File *image, char *outputFile){
		// Reads in the inputFile
    int ReturnRead = readFile(input, image);
		if (ReturnRead != 0){
			return ReturnRead;
		}
		if (checkIfFileBinary(image, input) == 0){
			printf("ERROR: Bad Magic Number (%s)", input);
			return BAD_MAGIC_NUMBER;
		}
		int ReturnWrite = write("./pgma2b", image, outputFile);
		if (ReturnWrite != 0){
			return ReturnWrite;
		}
    return EXIT_NO_ERRORS;
}
