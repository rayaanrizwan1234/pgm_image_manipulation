C = gcc
CFLAGS = -g -std=c99 -fmax-errors=1
MODULES = pgmRead.o pgmWrite.o pgmValidationWrite.o pgmValidation.o pgmCompare.o pgmWriteFunctions.o 
MAINS = pgmEcho.o pgmComp.o pgma2b.o pgmb2a.o pgmReduce.o
TARGETS = pgmEcho pgmComp pgma2b pgmb2a pgmReduce

all:    ${TARGETS}

clean:
	rm ${TARGET} ${MAINS} ${MODULES} *.o
pgmEcho: pgmEcho.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmEcho pgmEcho.o ${MODULES}
pgmEchoStructs: pgmEchoStructs.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmEchoStructs pgmEchoStructs.o ${MODULES}
pgmComp: pgmComp.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmComp pgmComp.o ${MODULES}
pgma2b: pgma2b.o ${MODULES}
	${CC} ${CCFLAGS} -o pgma2b pgma2b.o ${MODULES}
pgmb2a: pgmb2a.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmb2a pgmb2a.o ${MODULES}   
pgmReduce: pgmReduce.o ${MODULES}
	${CC} ${CCFLAGS} -o pgmReduce pgmReduce.o ${MODULES}
