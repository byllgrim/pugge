#include <stdio.h>
#include <stdlib.h>

#include "questions.h"
#include "utils.h"

static int  get_choice(void);
static void verify_choice(struct question *q, int c);

void
start_quiz(struct question *q){
	struct answer *a;
	int i, c;

	for (; q; q=q->next) {
		printf("%s\n", q->text);
		for (i = 1, a = q->answers; a; a = a->next, i++)
			printf("%d) %s\n", i, a->text);
		c = get_choice();
		verify_choice(q, c);
	}
}

int
get_choice(void)
{
	char *s;
	int i;

	s = xcalloc(BUFSIZ + 1, sizeof(*s));
	printf("Choice: ");
	fgets(s, BUFSIZ, stdin);
	i = atoi(s);
	free(s);
	return i;
	/* TODO is this messy? */
}

void
verify_choice(struct question *q, int c)
{
	while (!c /* TODO || c > max */) {
		printf("Please choose a valid number\n");
		c = get_choice();
	}

	if (get_answer(q, c)->correct)
		printf("Congratulations!!!!");
	else
		printf("The right answer is TODO");

	getchar(); /* press enter to continue */
}
