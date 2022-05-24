#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmWrite.h"

int checkFile(FILE *outputFile, File *image, char *input){
  if (outputFile == NULL)
      { /* NULL output file */
      /* free memory                   */
      free(image->commentLine);
      free(image->imageData);

      /* print an error message        */
      printf("ERROR: Output Failed (%s)\n", input);

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
