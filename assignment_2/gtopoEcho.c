#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include "gtopoDef.h"
#include "gtopoRead.h"
#include "gtopoEchoStructs.h"
#include "gtopoWrite.h"

/***********************************/
/* main routine                    */
/*                                 */
/* CLI parameters:                 */
/* argv[0]: executable name        */
/* argv[1]: input file name        */
/* argv[2]: output file name       */
/* returns 0 on success            */
/* non-zero error code on fail     */
/***********************************/

int main(int argc, char **argv)
	{ /* main() */
	/* check for correct number of arguments */
	if (argc == 1)
		{ /* wrong arg count */
		/* print an error message        */
		printf("Usage: %s inputImage.pgm width height outputImage.pgm", argv[0]);
		/* and return an error code      */
		return 0;
	} else if (argc != 5){
		printf("ERROR: Bad Argument Count");
		return EXIT_WRONG_ARG_COUNT;
	}
		//Create Pointer to Struct File
		File *file1 = malloc(sizeof(File));
		int width = atoi(argv[2]);
		int height = atoi(argv[3]);
		// Call readFile and write
	  readFile(argv[1], width, height, file1);
	 	write(argv[0], file1, argv[4]);
		printf("ECHOED!\n");
		return EXIT_NO_ERRORS;
}
