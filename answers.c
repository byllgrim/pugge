#include <stdio.h>
#include <stdlib.h>

#include "questions.h"
#include "utils.h"

static int get_choice(void);

void
start_quiz(struct question *q){
	struct answer *a;
	int i, c;

	for (; q; q=q->next) {
		printf("%s\n", q->text);
		for (i = 1, a = q->answers; a; a = a->next, i++)
			printf("%d) %s\n", i, a->text);
		c = get_choice();
		printf("TODO %d\n", c);
	}
}

int
get_choice(void)
{
	char *s;
	int i;

	s = xcalloc(BUFSIZ + 1, sizeof(*s));
	printf("Answer: ");
	fgets(s, BUFSIZ, stdin);
	i = atoi(s);
	free(s);
	return i;
	/* TODO is this messy? */
}
