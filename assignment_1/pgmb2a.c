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
 	if (argc != 3)
 		{ /* wrong arg count */
 		/* print an error message        */
     printf("Usage: ./pgmb2a inputImage.pgm outputImage.pgm");
 		/* and return an error code      */
 		return EXIT_WRONG_ARG_COUNT;
   }
   //Pointer to Struct
     File *image = malloc(sizeof(File));
     pgmb2a(argv[0],argv[1],argv[2],image);
     printf("CONVERTED\n");
   return EXIT_NO_ERRORS;
 }

int pgmb2a(char *convert, char *input1, char *outputFile, File *image){
  readFile(input1, image);
  write(convert, image, outputFile);
  return 0;
}
