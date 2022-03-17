#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmValidation.h"

int pgma2b(char *input1,File *image, char *outputFile){
  readFile(input1, image);
  fp = fopen(outputFile, "w");
  fprintf(image->imageData, 4, outputFile);
  fclose(fp);
  return 0;
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
		File *image = malloc(sizeof(File));
		pgma2b(argv[1],image, argv[2]);
} /* main() */
