#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmEchoStructs.h"
#include "pgmWrite.h"
#include <string.h>
#include "pgmb2a.h"
#include "pgmComp.h"
#include "pgma2b.h"


int Compare(char *input1, char *input2, File *image1, File *image2){
  // Reads 1st file
  readFile(input1, image1);
    // Reads 2nd file
  readFile(input2, image2);
    // Conditions to check if File attributes are equal
  if (
      image1->width == image2->width &&
      image1->height == image2->height
)
    {
      // Pointer to imageData
      unsigned char *nextGrayValue2 = image2->imageData;
      for(unsigned char *nextGrayValue1 = image1->imageData; nextGrayValue1 < image1->imageData + nImageBytes;nextGrayValue1++){
        // Read throught each image bit times by the maxGray and compare them to see if equal
        if((*nextGrayValue1 * image1->maxGray) != (*nextGrayValue2 * image2->maxGray)){
          printf("DIFFERENT\n");
          return EXIT_NO_ERRORS;
        }
        nextGrayValue2++;
      }
      printf("IDENTICAL\n");
     return EXIT_NO_ERRORS;
    }
    printf("DIFFERENT\n");
    return EXIT_NO_ERRORS;

}
