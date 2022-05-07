#include "pgmEchoStructs.h"
int checkInput(FILE *inputfile, char *input);
int checkMagicNumber(File *image, char *input);
int checkComment(char nextChar, File *image, FILE *inputFile);
int checkDimensions(File *image, FILE *inputFile, int scanCount, char *input);
int checkImageData(File *image, FILE *inputFile, char *input, long nImageBytes);
int checkLittleData(int scanCount, int grayValue, File *image, FILE *inputFile, char *input);
int checkTooMuchData(File *image, FILE *inputFile, char *input);
int checkImageMemory(File *image);
int checkIfFileBinary(File *image, char *input);
int checkIfFileAscii(File *image, char *input);
