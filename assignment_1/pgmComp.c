#include <stdio.h>
#include <stdlib.h>
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmEchoStructs.h"
#include "pgmWrite.h"
#include <string.h>
#include "pgmb2a.h"
#include "pgmComp.h"
#include "pgma2b.h"

int main(int argc, char **argv)
	{ /* main() */
	/* check for correct number of arguments */
	if (argc == 1)
		{ /* If no parameters were given */
		/* print an error message        */
    printf("Usage: ./pgmComp inputImage.pgm inputImage.pgm\n");
		/* and return an error code      */
		return 0;
	} else if (argc != 3){
		printf("ERROR: Bad Argument Count\n");
		return EXIT_WRONG_ARG_COUNT;
	}/* wrong arg count */
		// Creates to two pointers for two images
		File *file1 = malloc(sizeof(File));
    File *file2 = malloc(sizeof(File));
		Compare(argv[1], argv[2], file1, file2);
		return EXIT_NO_ERRORS;
}
