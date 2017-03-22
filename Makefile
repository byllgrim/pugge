CC = cc
CFLAGS = -Os -pedantic-errors -std=c89 -Wall -Wextra

TARG = pugge
SRC = ${TARG}.c file_handling.c
OBJ = ${SRC:.c=.o}

all: ${TARG}

${TARG}: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

.c.o:
	${CC} -c ${CFLAGS} $<

clean:
	rm -f ${OBJ} ${TARG}
