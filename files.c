/* This code is licensed under the Unlicense; see LICENSE for details. */
#include <stdio.h>
#include <stdlib.h>

#include "questions.h"
#include "utils.h"

static struct question *parse_file(char *filename, struct question *q);
static struct question *parse_line(char *line, struct question *q);

struct question *
parse_all_files(char **files)
{
	int i;
	struct question *first, *last;

	first = last = xcalloc(1, sizeof(first));

	for (i = 0; files[i]; i++)
		last = parse_file(files[i], last);

	return first;
}

struct question *
parse_file(char *filename, struct question *q)
{
	FILE *file;
	char *buffer;

	file = fopen(filename, "r");
	if (!file)
		kill_program("file not found: %s\n", filename);

	buffer = xcalloc(MAX_LEN, sizeof(char));
	while (fgets(buffer, MAX_LEN, file))
		q = parse_line(buffer, q);

	free(buffer);
	return (void*)0;
}

struct question *
parse_line(char *line, struct question *q)
{
	if (line[0] == '#') /* ignore comment lines beginning with # */
		return q;

	if (line[0] == '\n') {
		if (q->text) /* current question is done */
			return q->next = xcalloc(1, sizeof(q));
		else
			return q; /* waiting for question */
	}

	if (!q->text)
		set_question_text(line, q);
	else
		append_answer(line, q);

	return q;
}
