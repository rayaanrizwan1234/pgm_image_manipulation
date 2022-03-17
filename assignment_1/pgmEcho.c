#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmEchoStructs.h"
#include "pgmWrite.h"
#include "pgmComp.h"

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
	if (argc != 3)
		{ /* wrong arg count */
		/* print an error message        */
		printf("Usage: ./pgmEcho inputImage.pgm outputImage.pgm");
		/* and return an error code      */
		return EXIT_WRONG_ARG_COUNT;
	} else{
		printf("%s\n",argv[1]);
		File *file1 = malloc(sizeof(File));
		readFile(argv[1], file1);
		write(argv[0], file1, argv[2]);
	}

}
