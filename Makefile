CC = cc
TARG = pugge
OBJ = ${TARG}.o

all: ${TARG}

${TARG}: ${OBJ} #May fail when new .c files are added
	${CC} -o $@ ${OBJ} ${LDFLAGS}

.c.o:
	${CC} -c ${CFLAGS} $<

clean:
	rm -f ${OBJ} ${TARG}

