CC = cc
CFLAGS = -Os -pedantic-errors -std=c89 -Wall -Wextra

TARG = pugge
SRC = ${TARG}.c files.c questions.c utils.c
OBJ = ${SRC:.c=.o}

all: ${TARG}

${TARG}: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

.c.o:
	${CC} -c ${CFLAGS} $<

clean:
	rm -f ${OBJ} ${TARG}
