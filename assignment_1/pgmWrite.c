#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmWrite.h"
#include "pgmValidationWrite.h"
int write (char *input, File *file1) {
	FILE *outputFile = fopen(input, "w");

	  nImageBytes = file1->width * file1->height * sizeof(unsigned char);
	 /* check whether file opening worked     */
	 checkFile(outputFile, file1);
	 /* write magic number, size & gray value */
	//  size_t nBytesWritten  = fprintf(outputFile, "P2\n%d %d\n%d\n", file1->width, file1->height, file1->maxGray);
	size_t nBytesWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", file1->width, file1->height, file1->maxGray);
	 /* check that dimensions wrote correctly */
		checknBytesWritten(nBytesWritten, file1);

			 /* pointer for efficient write code      */
			 for (unsigned char *nextGrayValue = file1->imageData; nextGrayValue < file1->imageData + nImageBytes; nextGrayValue++)
							 { /* per gray value */
			 /* get next char's column        */
			 int nextCol = (nextGrayValue - file1->imageData + 1) % file1->width;

			 /* write the entry & whitespace  */
			 nBytesWritten = fprintf(outputFile, "%d%c", *nextGrayValue, (nextCol ? ' ' : '\n') );

			 checknBytesWritten(nBytesWritten, file1);
			 } /* per gray value */

	 /* at this point, we are done and can exit with a success code */
	 return EXIT_NO_ERRORS;
}
