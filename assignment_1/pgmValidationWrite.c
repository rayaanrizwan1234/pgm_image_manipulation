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
      printf("Error: Output Failed (%s)", input);

      /* return an error code          */
      return OUTPUT_FAILED;
      } /* NULL output file */
      return 0;
}

int fileExtension(File * image, char *input){
  // Variables to hold the extension of the inputfile
  char *extension = NULL;
  char *ext = "pgm";
  // COmputes the extension and stores it in extension
  const char *dot = strchr(input, '.');
  if(!dot || dot == input) extension = "";
  extension = dot + 1;
  // CHecks if the extension is pgm
  if (strcmp(extension, ext) != 0){
    printf("Error: Output Failed (%s)", input);
    return OUTPUT_FAILED;
  }
  return EXIT_NO_ERRORS;
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
