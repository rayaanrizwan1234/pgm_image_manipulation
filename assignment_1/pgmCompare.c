#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmEchoStructs.h"
#include "pgmWrite.h"
#include "pgmComp.h"

int main(int argc, char **argv)
	{ /* main() */
	/* check for correct number of arguments */
	if (argc != 3)
		{ /* wrong arg count */
		/* print an error message        */
		printf("Usage: ./pgmComp inputImage.pgm inputImage.pgm");
		/* and return an error code      */
		return EXIT_WRONG_ARG_COUNT;
	} else{
		File *file1 = malloc(sizeof(File));
    File *file2 = malloc(sizeof(File));
		Compare(argv[1], argv[2], file1, file2);
	}

} 
