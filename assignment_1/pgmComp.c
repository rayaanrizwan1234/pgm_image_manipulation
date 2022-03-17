#include <stdio.h>
#include <stdlib.h>
#include "pgmDef.h"
#include "pgmRead.h"
#include "pgmEchoStructs.h"
#include "pgmWrite.h"
#include "string.h"

int Compare(char *input1, char *input2, File *image1, File *image2){
  printf("1\n");
  readFile(input1, image1);
    printf("2\n");
  readFile(input2, image2);
    printf("3\n");
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
