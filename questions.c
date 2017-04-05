#include <string.h>

#include "questions.h"
#include "utils.h"

void
set_question_text(char *src, struct question *q)
{
	size_t len;

	len = strlen(src);
	q->text = xcalloc(len + 1, sizeof(char));

	strncpy(q->text, src, len); /* TODO check return value? */
	/* TODO don't copy \n  */
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
	a->text = xcalloc(len + 1, sizeof(char));
	strncpy(a->text, src, len); /* TODO check return value? */
	/* TODO check ! for correct answer */
}
