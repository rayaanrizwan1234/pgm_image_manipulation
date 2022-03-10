/***********************************/
/* COMP 1921M Programming Project  */
/* 2021-22 Spring Semester         */
/*                                 */
/* Hamish Carr                     */
/***********************************/

/***********************************/
/* A first iteration to take a pgm */
/* file in binary and convert to   */
/* ASCII or vice versa             */
/***********************************/

/***********************************/
/* Main Routine                    */
/***********************************/

/* library for I/O routines        */
#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmEchoStructs.h"

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


int write (char *input, File *file1) {
	FILE *outputFile = fopen(input, "w");

	  nImageBytes =file1->width * file1->height * sizeof(unsigned char);
	 /* check whether file opening worked     */
	 if (outputFile == NULL)
			 { /* NULL output file */
			 /* free memory                   */
			 free(file1->commentLine);
			 free(file1->imageData);

			 /* print an error message        */
			 printf("Error: Failed to write pgm image to file %s\n", input);

			 /* return an error code          */
			 return EXIT_BAD_OUTPUT_FILE;
			 } /* NULL output file */

	 /* write magic number, size & gray value */
	 size_t nBytesWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", file1->width, file1->height, file1->maxGray);

	 /* check that dimensions wrote correctly */
	 if (nBytesWritten < 0)
			 { /* dimensional write failed    */
			 /* free memory                   */
			 free(file1->commentLine);
			 free(file1->imageData);

			 /* print an error message        */
			 printf("Error: Failed to write pgm image to file %s\n", input);

			 /* return an error code          */
			 return EXIT_BAD_OUTPUT_FILE;
			 } /* dimensional write failed    */

			 /* pointer for efficient write code      */
			 for (unsigned char *nextGrayValue = file1->imageData; nextGrayValue < file1->imageData + nImageBytes; nextGrayValue++)
							 { /* per gray value */
			 /* get next char's column        */
			 int nextCol = (nextGrayValue - file1->imageData + 1) % file1->width;

			 /* write the entry & whitespace  */
			 nBytesWritten = fprintf(outputFile, "%d%c", *nextGrayValue, (nextCol ? ' ' : '\n') );

			 /* sanity check on write         */
			 if (nBytesWritten < 0)
					 { /* data write failed   */
					 /* free memory           */
					 free(file1->commentLine);
					 free(file1->imageData);

					 /* print error message   */
					 printf("Error: Failed to write pgm image to file %s\n", input);

					 /* return an error code  */
					 return EXIT_BAD_OUTPUT_FILE;
					 } /* data write failed   */
			 } /* per gray value */

	 /* at this point, we are done and can exit with a success code */
	 return EXIT_NO_ERRORS;
}

int main(int argc, char **argv)
	{ /* main() */
	/* check for correct number of arguments */
	if (argc != 3)
		{ /* wrong arg count */
		/* print an error message        */
		printf("Usage: %s input_file output_file\n", argv[0]);
		/* and return an error code      */
		return EXIT_WRONG_ARG_COUNT;
		} /* wrong arg count */
		printf("%s\n",argv[1]);
		File *image = malloc(sizeof(File));
		readFile(argv[1], image);
		write(argv[2], image);

} /* main() */
