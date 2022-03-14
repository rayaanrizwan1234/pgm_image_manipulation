#include <stdlib.h>
#include <stdio.h>
#include "pgmEchoStructs.h"
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmValidation.h"

int readFile (char *input, File *image) {
    // Initialize all the data in the struct
    image->magic_number[0] = '0';
    image->magic_number[1] = '0';
    image->magic_Number = (unsigned short *) image->magic_number;
    image->commentLine = NULL;
    image->width = 0;
    image->height = 0;
    image->maxGray = 255;
    image->imageData = NULL;

    // reading in the data
    FILE *inputFile = fopen(input, "r");
    // fails to read in file, returns error from pgmDef.h
  	checkInput(inputFile);
    // reads in Magic Number from file. Determines file type
    image->magic_number[0] = getc(inputFile);
    image->magic_number[1] = getc(inputFile);
    printf("%u\n", image->magic_number[0] );
    printf("%u\n", image->magic_number[1] );

    int scanCount = fscanf(inputFile, " ");
    char nextChar = fgetc(inputFile);

		checkComment(nextChar, image, inputFile);

    scanCount = fscanf(inputFile, "%u %u %u", &(image->width), &(image->height), &(image->maxGray));
    printf("%u\n",image->width);
    printf("%u\n",image->height);
    printf("%u\n",image->maxGray);

  	checkDimensions(image->width, image->height, image->maxGray, image, inputFile, scanCount);

    nImageBytes =image->width * image->height * sizeof(unsigned char);
    image->imageData = (unsigned char *) malloc(nImageBytes);
  	checkImageData(image->imageData, image, inputFile);
    for(unsigned char *nextGrayValue = image->imageData; nextGrayValue < image->imageData + nImageBytes;nextGrayValue++){
        int grayValue = -1;
        int scanCount = fscanf(inputFile, "%u", &grayValue);
        checkGrayValue(scanCount, grayValue, image, inputFile);
        *nextGrayValue = (unsigned char) grayValue;
    }
fclose(inputFile);
return EXIT_NO_ERRORS;
}
