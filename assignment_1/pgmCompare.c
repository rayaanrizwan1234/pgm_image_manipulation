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
  int ReturnRead1 = readFile(input1, image1);
  if(ReturnRead1 != 0){
    return ReturnRead1;
  }
    // Reads 2nd file
  int ReturnRead2 = readFile(input2, image2);
  if(ReturnRead2 != 0){
    return ReturnRead2;
  }
// Check while file I have converted to ASCII
  int convert = 0;
  // Checks if they are of different types e.g ASCII and binary
    if(image1->magic_number[1] != image2->magic_number[1]){
      // If binary then conver to ASCII
      if (image1->magic_number[1] == 53){
       write("./pgmb2a", image1, input1);
        // If input1 is converted to ASCII we change convert to 1
        convert = 1;
      } else {
        write("./pgmb2a", image2, input2);
        // Convert set to 2 if 2nd file is changed to ASCII
        convert = 2;
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
        // if (convert == 1){
        //   readFile(input1, image1);
        //   write("./pgma2b", image1, input1);
        // } else if (convert == 2){
        //   File *convertBack = malloc(sizeof(File));
        //   readFile(input2, convertBack);
        //   printf("Pic 3 %u\n", convertBack -> magic_number[1]);
        //   write("./pgma2b", convertBack, input2);
        // }
        printf("IDENTICAL\n");
        return EXIT_NO_ERRORS;
      }
    }
    // if (convert == 1){
    //   write("./pgma2b", image1, input1);
    // } else if (convert == 2){
    //   write("./pgma2b", image2, input2);
    // }
      printf("DIFFERENT\n");
      return EXIT_NO_ERRORS;
}
