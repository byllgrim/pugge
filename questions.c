#include <string.h>

#include "questions.h"
#include "utils.h"

void
set_question_text(char *src, struct question *q)
{
	size_t len;

	len = strlen(src);
	q->text = xcalloc(len, sizeof(char));

	strncpy(q->text, src, len); /* TODO check return value? */
	q->text[len - 1] = '\0';
	/* TODO export this function? */
}

void
append_answer(char *src, struct question *q)
{
	struct answer *a;
	size_t len;

	if (!q->answers)
		q->answers = xcalloc(1, sizeof(q->answers));

	for (a = q->answers; a->text; a = a->next)
		if (!a->next)
			a->next = xcalloc(1, sizeof(q->answers));

	len = strlen(src);

	if (src[0] == '!'){
		a->correct = 1;
		src++;
		len--;
	}

	a->text = xcalloc(len, sizeof(char));
	strncpy(a->text, src, len); /* TODO check return value? */
	a->text[len - 1] = '\0';
}
