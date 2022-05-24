C = gcc
CFLAGS = -g -std=c99 -fmax-errors=1
MODULES = gtopoRead.o gtopoWrite.o gtopoValidationWrite.o gtopoValidation.o gtopoWriteFunctions.o 
MAINS = gtopoEcho.o gtopoComp.o gtopoReduce.o
TARGETS = gtopoEcho gtopoComp pgmReduce 

all:    ${TARGETS}

clean:
	rm ${TARGET} ${MAINS} ${MODULES} *.o
gtopoEcho: gtopoEcho.o ${MODULES}
	${CC} ${CCFLAGS} -o gtopoEcho gtopoEcho.o ${MODULES}
gtopoEchoStructs: gtopoEchoStructs.o ${MODULES}
	${CC} ${CCFLAGS} -o gtopoEchoStructs gtopoEchoStructs.o ${MODULES}
gtopoComp: gtopoComp.o ${MODULES}
	${CC} ${CCFLAGS} -o gtopoComp gtopoComp.o ${MODULES}
gtopoReduce: gtopoReduce.o ${MODULES}
	${CC} ${CCFLAGS} -o gtopoReduce gtopoReduce.o ${MODULES}
