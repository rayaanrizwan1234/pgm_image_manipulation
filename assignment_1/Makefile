C = gcc
CFLAGS = -g -std=c99 -fmax-errors=1
MODULES = pgmRead.o pgmWrite.o pgmValidationWrite.o pgmValidation.o pgmComp.o 
MAINS = pgmEcho.o pgmCompare.o pgma2b.o pgmb2a.o pgmReduce.o
TARGETS = pgmEcho pgmCompare pgma2b pgmb2a pgmReduce

all:    ${TARGETS}

clean:
	rm ${TARGET} ${MAINS} ${MODULES} *.o
pgmEcho: pgmEcho.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmEcho pgmEcho.o ${MODULES}
pgmEchoStructs: pgmEchoStructs.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmEchoStructs pgmEchoStructs.o ${MODULES}
pgmCompare: pgmCompare.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmCompare pgmCompare.o ${MODULES}
pgma2b: pgma2b.o ${MODULES}
	${CC} ${CCFLAGS} -o pgma2b pgma2b.o ${MODULES}
pgmb2a: pgmb2a.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmb2a pgmb2a.o ${MODULES}   
pgmReduce: pgmReduce.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmReduce pgmReduce.o ${MODULES}
