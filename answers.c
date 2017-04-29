#include <stdio.h>

#include "questions.h"

void start_quiz(struct question *q){
	struct answer *a;
	int i;

	for (; q; q=q->next) {
		printf("%s\n", q->text);
		for (i = 1, a = q->answers; a; a = a->next, i++)
			printf("%d) %s\n", i, a->text);
		puts("Answer: TODO");
	}
}
