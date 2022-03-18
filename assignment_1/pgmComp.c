#include <stdio.h>
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
  // Checks if they are of different types e.g ASCII and binary
    if(image1->magic_number[1] != image2->magic_number[1]){
      // If binary then conver to ASCII
      if (image1->magic_number[1] == 53){
        // pgmb2a("./pgmb2a", input1, input1, image1);
        write("./pgmb2a", image1, input1);
      } else {
        // pgmb2a("./pgmb2a", input2, input2, image2);
          write("./pgmb2a", image2, input2);
      }
    }
    // Conditions to check if File attributes are equal
  if (
      image1->width == image2->width &&
      image1->height == image2->height &&
      image1->maxGray == image2->maxGray &&
      image1->commentLine == image2->commentLine
    )
    {
      if(memcmp(image1->imageData, image2->imageData, image1->height*image1->width) == 0){
        printf("IDENTICAL\n");
        return EXIT_NO_ERRORS;
      }
    }
      printf("DIFFERENT\n");
      return 1;
}
//image1->imageData == image2->imageData
