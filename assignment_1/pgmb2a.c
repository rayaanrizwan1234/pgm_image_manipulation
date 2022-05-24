#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmValidation.h"
#include "pgmb2a.h"
#include "pgmWrite.h"


 int main(int argc, char **argv)
 	{ /* main() */
 	/* check for correct number of arguments */
  if (argc == 1)
		{ /* If no parameterswere given */
		/* print an error message        */
    printf("Usage: ./pgmb2a inputImage.pgm outputImage.pgm\n");
		/* and return an error code      */
		return 0;
	} else if (argc != 3){
		printf("ERROR: Bad Argument Count\n");
		return EXIT_WRONG_ARG_COUNT;
	}/* wrong arg count */
   //Pointer to Struct
     File *image = malloc(sizeof(File));
    pgmb2a(argv[0],argv[1],argv[2],image);
     printf("CONVERTED\n");
     return EXIT_NO_ERRORS;
 }

int pgmb2a(char *convert, char *inputFile, char *outputFile, File *image){

  // Reads in the inputFile
  readFile(inputFile, image);
  // Checks if the file inputted is ASCII and if so it will give an error
  if (checkIfFileAscii(image, inputFile) == 0){
    printf("ERROR: Bad Magic Number (%s)\n", inputFile);
    exit(BAD_MAGIC_NUMBER);
  }
  write("./pgmb2a", image, outputFile);
  return EXIT_NO_ERRORS;
}
