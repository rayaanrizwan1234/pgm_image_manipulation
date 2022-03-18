#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmWrite.h"

int checkFile(FILE *outputFile, File *file1){
  if (outputFile == NULL)
      { /* NULL output file */
      /* free memory                   */
      free(file1->commentLine);
      free(file1->imageData);

      /* print an error message        */
      printf("Error: Failed to write pgm image to file \n");

      /* return an error code          */
      return EXIT_BAD_INPUT_FILE ;
      } /* NULL output file */
      return 0;
}

int checknBytesWritten(size_t nBytesWritten, File *file1){
  if (nBytesWritten < 0)
      { /* dimensional write failed    */
      /* free memory                   */
      free(file1->commentLine);
      free(file1->imageData);

      /* print an error message        */
      printf("Error: Failed to read bytes");

      /* return an error code          */
      return NBYTESWRITTENFAIL;
      } /* dimensional write failed    */
      return 0;
}
