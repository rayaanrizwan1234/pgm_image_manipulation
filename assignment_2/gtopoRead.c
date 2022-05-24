#include <stdlib.h>
#include <stdio.h>
#include "gtopoDef.h"
#include "gtopoRead.h"
#include "gtopoEchoStructs.h"
#include "gtopoWrite.h"


int readFile (char *input, int width, int height, File *image) {
image->width = width;
image->height = height;
image->imageData = NULL;

// reading in the data
FILE *inputFile = fopen(input, "r");
// fails to read in file, returns error from pgmDef.h
// Checks the file being inputted
 checkInput(inputFile, input);

// scans for white spaces in the image logic
// // // scans for the white spaces if present in the code
// char nextChar = fgetc(inputFile);

// allocate the data pointer
nImageBytes = image->width * image->height * sizeof(unsigned char);
printf("%d\n", nImageBytes);
image->imageData = (unsigned char *) malloc(nImageBytes);

// Checks if malloc allocated memory
checkImageMemory(image);

fread(image->imageData, sizeof(unsigned char), nImageBytes, inputFile);

checkTooMuchData(image, inputFile, input);

// close the file, no longer needed
fclose(inputFile);

return EXIT_NO_ERRORS;
}
///vol/scratch/SoC/COMP1921/COMP1921A2_handout/dems/gtopo_reduced_0_0.dem
