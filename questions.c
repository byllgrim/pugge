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
