#include <stdlib.h>
#include <stdio.h>
#include "gtopoDef.h"
#include "gtopoRead.h"
#include "gtopoEchoStructs.h"
#include "gtopoWrite.h"

int checkFile(FILE *outputFile, File *image, char *input){
  if (outputFile == NULL)
      { /* NULL output file */
      /* free memory                   */
      free(image->imageData);

      /* print an error message        */
      printf("ERROR: Output Failed (%s)", input);

      /* return an error code          */
      exit(OUTPUT_FAILED);
      } /* NULL output file */
      return 0;
}

int fileExtension(char *input){
if(!(strchr(input, '.pgm'))){
  printf("ERROR: Output Failed (%s)", input);
  /* return an error code          */
  exit(OUTPUT_FAILED);
}
return EXIT_NO_ERRORS;
}
int checknBytesWritten(size_t nBytesWritten, File *file1){
  if (nBytesWritten < 0)
      { /* dimensional write failed    */
      /* free memory                   */
      free(file1->imageData);

      /* print an error message        */
      printf("Error: Failed to read bytes");

      /* return an error code          */
      return NBYTESWRITTENFAIL;
      } /* dimensional write failed    */
      return 0;
}
