/***********************************/
/* COMP 1921M Programming Project  */
/* 2021-22 Spring Semester         */
/*                                 */
/* Hamish Carr                     */
/***********************************/

/***********************************/
/* A first iteration to take a pgm */
/* file in binary and convert to   */
/* ASCII or vice versa             */
/***********************************/

/***********************************/
/* Main Routine                    */
/***********************************/

/* library for I/O routines        */
#include <stdio.h>

/* library for memory routines     */
#include <stdlib.h>

#define EXIT_NO_ERRORS 0
#define EXIT_WRONG_ARG_COUNT 1
#define EXIT_BAD_INPUT_FILE 2
#define EXIT_BAD_OUTPUT_FILE 3

#define MAGIC_NUMBER_RAW_PGM 0x3550
#define MAGIC_NUMBER_ASCII_PGM 0x3250
#define MIN_IMAGE_DIMENSION 1
#define MAX_IMAGE_DIMENSION 65536
#define MAX_COMMENT_LINE_LENGTH 128

/***********************************/
/* main routine                    */
/*                                 */
/* CLI parameters:                 */
/* argv[0]: executable name        */
/* argv[1]: input file name        */
/* argv[2]: output file name       */
/* returns 0 on success            */
/* non-zero error code on fail     */
/***********************************/

typedef struct _file {
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
	unsigned int width, height;

	/* maximum gray value (assumed)	         */
	/* make it an integer for ease	         */
	unsigned int maxGray;

	/* pointer to raw image data	         */
	unsigned char *imageData;
} File;

int main(int argc, char **argv)
	{ /* main() */
	/* check for correct number of arguments */
	if (argc != 3)
		{ /* wrong arg count */
		/* print an error message        */
		printf("Usage: %s input_file output_file\n", argv[0]);
		/* and return an error code      */
		return EXIT_WRONG_ARG_COUNT;
		} /* wrong arg count */

	/* variables for storing the image       */
    	/* this is NOT good modularisation       */
    	/* and you will eventually replace it    */
    	/* for now, leave it here                */
	/* now start reading in the data         */
	/* try to open the file for text I/O     */
	/* in ASCII mode b/c the header is text  */
	FILE *inputFile = fopen(argv[1], "r");

	/* if it fails, return error code        */
	if (inputFile == NULL)
		return EXIT_BAD_INPUT_FILE;

		File *file1 = malloc(sizeof(File));

			 file1->magic_number[0] = '0';
			 file1->magic_number[1] = '0';

			  file1->width = 0;
				file1->height = 0;

				file1->maxGray = 255;
	/* read in the magic number              */
	file1->magic_number[0] = getc(inputFile);
	file1->magic_number[1] = getc(inputFile);

	file1-> magic_Number = (unsigned short *) file1->magic_number;
printf("%u\n",file1->magic_number[0]);
printf("%u\n",file1->magic_number[1]);

	/* sanity check on the magic number      */
	// if ( file1->magic_Number != MAGIC_NUMBER_RAW_PGM)
	// 	{ /* failed magic number check   */
	// 	/* be tidy: close the file       */
	// 	fclose(inputFile);
	// 	printf("Somethings wrong\n");
	// 	/* print an error message */
	// 	printf("Error: Failed to read pgm image from file %s\n", argv[1]);
	//
	// 	/* and return                    */
	// 	return EXIT_BAD_INPUT_FILE;
	// 	} /* failed magic number check   */

	/* scan whitespace if present            */
	int scanCount = fscanf(inputFile, " ");

	/* check for a comment line              */
	char nextChar = fgetc(inputFile);
	if (nextChar == '#')
		{ /* comment line                */
		/* allocate buffer               */
		file1->commentLine = (char *) malloc(MAX_COMMENT_LINE_LENGTH);
		/* fgets() reads a line          */
		/* capture return value          */
		char *commentString = fgets(file1->commentLine, MAX_COMMENT_LINE_LENGTH, inputFile);
		/* NULL means failure            */
		if (commentString == NULL)
			{ /* NULL comment read   */
			/* free memory           */
			free(file1->commentLine);
			/* close file            */
			fclose(inputFile);

			/* print an error message */
			printf("Error: Failed to read pgm image from file %s\n", argv[1]);

			/* and return            */
			return EXIT_BAD_INPUT_FILE;
			} /* NULL comment read   */
		} /* comment line */
	else
		{ /* not a comment line */
		/* put character back            */
		ungetc(nextChar, inputFile);
		} /* not a comment line */

	/* read in width, height, grays          */
	/* whitespace to skip blanks             */
	scanCount = fscanf(inputFile, " %u %u %u", &(file1->width), &(file1->height), &(file1->maxGray));

	/* sanity checks on size & grays         */
	/* must read exactly three values        */
	if 	(
		(scanCount != 3				)	||
		(file1->width 	< MIN_IMAGE_DIMENSION	) 	||
		(file1->width 	> MAX_IMAGE_DIMENSION	) 	||
		(file1->height < MIN_IMAGE_DIMENSION	) 	||
		(file1->height > MAX_IMAGE_DIMENSION	) 	||
		(file1->maxGray	!= 255		)
		)
		{ /* failed size sanity check    */
		/* free up the memory            */
		free(file1->commentLine);

		/* be tidy: close file pointer   */
		fclose(inputFile);

		/* print an error message */
		printf("Error: Failed to read pgm image from file %s\n", argv[1]);

		/* and return                    */
		return EXIT_BAD_INPUT_FILE;
		} /* failed size sanity check    */

	/* allocate the data pointer             */
	long nImageBytes = file1->width * file1->height * sizeof(unsigned char);
	file1->imageData = (unsigned char *) malloc(nImageBytes);

	/* sanity check for memory allocation    */
	if (file1->imageData == NULL)
		{ /* malloc failed */
		/* free up memory                */
		free(file1->commentLine);

		/* close file pointer            */
		fclose(inputFile);

		/* print an error message */
		printf("Error: Failed to read pgm image from file %s\n", argv[1]);

		/* return error code             */
		return EXIT_BAD_INPUT_FILE;
		} /* malloc failed */

	/* pointer for efficient read code       */
	for (unsigned char *nextGrayValue = file1->imageData; nextGrayValue < file1->imageData + nImageBytes; nextGrayValue++)
		{ /* per gray value */
		/* read next value               */
		int grayValue = -1;
		int scanCount = fscanf(inputFile, " %u", &grayValue);

		/* sanity check	                 */
		if ((scanCount != 1) || (grayValue < 0) || (grayValue > 255))
			{ /* fscanf failed */
			/* free memory           */
			free(file1->commentLine);
			free(file1->imageData);

			/* close file            */
			fclose(inputFile);

			/* print error message   */
			printf("Error: Failed to read pgm image from file %s\n", argv[1]);

			/* and return            */
			return EXIT_BAD_INPUT_FILE;
			} /* fscanf failed */

		/* set the pixel value           */
		*nextGrayValue = (unsigned char) grayValue;
		} /* per gray value */

	/* we're done with the file, so close it */
	fclose(inputFile);

	/* open a file for writing               */
	FILE *outputFile = fopen(argv[2], "w");

	/* check whether file opening worked     */
	if (outputFile == NULL)
		{ /* NULL output file */
		/* free memory                   */
		free(file1->commentLine);
		free(file1->imageData);

		/* print an error message        */
		printf("Error: Failed to write pgm image to file %s\n", argv[2]);

		/* return an error code          */
		return EXIT_BAD_OUTPUT_FILE;
		} /* NULL output file */

	/* write magic number, size & gray value */
	size_t nBytesWritten = fprintf(outputFile, "P2\n%d %d\n%d\n", file1->width, file1->height, file1->maxGray);

	/* check that dimensions wrote correctly */
	if (nBytesWritten < 0)
		{ /* dimensional write failed    */
		/* free memory                   */
		free(file1->commentLine);
		free(file1->imageData);

		/* print an error message        */
		printf("Error: Failed to write pgm image to file %s\n", argv[2]);

		/* return an error code          */
		return EXIT_BAD_OUTPUT_FILE;
		} /* dimensional write failed    */

        /* pointer for efficient write code      */
        for (unsigned char *nextGrayValue = file1->imageData; nextGrayValue < file1->imageData + nImageBytes; nextGrayValue++)
                { /* per gray value */
		/* get next char's column        */
		int nextCol = (nextGrayValue - file1->imageData + 1) % file1->width;

		/* write the entry & whitespace  */
		nBytesWritten = fprintf(outputFile, "%d%c", *nextGrayValue, (nextCol ? ' ' : '\n') );

		/* sanity check on write         */
		if (nBytesWritten < 0)
			{ /* data write failed   */
			/* free memory           */
			free(file1->commentLine);
			free(file1->imageData);

			/* print error message   */
			printf("Error: Failed to write pgm image to file %s\n", argv[2]);

			/* return an error code  */
			return EXIT_BAD_OUTPUT_FILE;
			} /* data write failed   */
		} /* per gray value */

	/* at this point, we are done and can exit with a success code */
	return EXIT_NO_ERRORS;
} /* main() */
