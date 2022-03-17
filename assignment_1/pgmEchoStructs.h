#ifndef FILE_H
#define FILE_H

typedef struct File {
	/* the magic number		         */
	/* stored as two bytes to avoid	         */
	/* problems with endianness	         */
	/* Raw:    0x5035 or P5		         */
	/* ASCII:  0x5032 or P2		         */
	unsigned char magic_number[2];
	unsigned short *magic_Number;

	/* we will store ONE comment	         */
	char *commentLine;

	/* the logical width & height	         */
	/* note: cannot be negative	         */
	unsigned int width;
	unsigned int height;

	/* maximum gray value (assumed)	         */
	/* make it an integer for ease	         */
	unsigned int maxGray;

	/* pointer to raw image data	         */
	unsigned char *imageData;

} File;

#endif
