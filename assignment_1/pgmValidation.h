#include "pgmEchoStructs.h"
int checkInput(FILE *inputfile, char *input);
int checkMagicNumber(File *image, char *input);
int checkComment(char nextChar, File *image, FILE *inputFile);
int checkDimensions(File *image, FILE *inputFile, int scanCount, char *input);
int checkImageData(unsigned char *imageData, File *image, FILE *inputFile, char *input);
int checkGrayValue(int scanCount, int grayValue, File *image, FILE *inputFile);
int checkImageMemory(File *image);
int checkIfFileBinary(File *image, char *input);
int checkIfFileAscii(File *image, char *input);
