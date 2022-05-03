#include "pgmEchoStructs.h"
int writeBinary(FILE *outputFile, File *image, unsigned char *nextGrayValue, long nImageBytes);
int writeAscii(FILE *outputFile, File *image, unsigned char *nextGrayValue, long nImageBytes);
