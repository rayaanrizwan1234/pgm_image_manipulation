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
    printf("Usage: ./pgmb2a inputImage.pgm outputImage.pgm");
		/* and return an error code      */
		return 0;
	} else if (argc != 3){
		printf("ERROR: Bad Argument Count");
		return EXIT_WRONG_ARG_COUNT;
	}/* wrong arg count */
   //Pointer to Struct
     File *image = malloc(sizeof(File));

   int Returnpgmb2a = pgmb2a(argv[0],argv[1],argv[2],image);
   if (Returnpgmb2a == 0){
     printf("CONVERTED\n");
     return EXIT_NO_ERRORS;
   } else {
     return Returnpgmb2a;
   }
 }

int pgmb2a(char *convert, char *inputFile, char *outputFile, File *image){

  // Reads in the inputFile
  int ReturnRead = readFile(inputFile, image);
  if (ReturnRead != 0){
    return ReturnRead;
  }
  if (checkIfFileAscii(image, inputFile) == 0){
    printf("ERROR: Bad Magic Number (%s)", inputFile);
    return BAD_MAGIC_NUMBER;
  }
  int ReturnWrite = write(convert, image, outputFile);
  if (ReturnWrite != 0){
    return ReturnWrite;
  }
  return EXIT_NO_ERRORS;
}
