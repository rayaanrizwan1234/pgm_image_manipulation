#include "pgmEchoStructs.h"
int checkInput(FILE *inputfile);
int checkMagicNumber(File *image);
int checkComment(char nextChar, File *image, FILE *inputFile);
int checkDimensions(int width, int height, int maxGray, File *image, FILE *inputFile, int scanCount);
int checkImageData(unsigned char *imageData, File *image, FILE *inputFile);
int checkGrayValue(int scanCount, int grayValue, File *image, FILE *inputFile);
int checkImageMemory(File *image);
