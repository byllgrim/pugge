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
append_choice(char *src, struct question *q)
{
	struct choice *c;
	size_t len;

	if (!q->choices)
		q->choices = xcalloc(1, sizeof(q->choices));

	for (c = q->choices; c->text; c = c->next) {
		if (!c->next)
			c->next = xcalloc(1, sizeof(q->choices));
	}

	len = strlen(src);
	c->text = xcalloc(len + 1, sizeof(char));

	strncpy(c->text, src, len); /* TODO check return value? */
	/* TODO check ! for correct answer */
}
