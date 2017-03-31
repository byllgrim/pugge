/* This code is licensed under the Unlicense; see LICENSE for details. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pugge.h"
#include "util.h"

struct question *parse_file(char *filename, struct question *q);
struct question *parse_line(char *line, struct question *q);
void set_question_text(char *src, struct question *q); /* TODO export? */

struct question *
parse_all_files(char **files)
{
	int i;
	struct question *first, *last;

	first = last = calloc(1, sizeof(first));
	if (!first)
		kill_program("parse_all_files: calloc failed\n");

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

	buffer = calloc(MAX_LEN, sizeof(char));
	while (fgets(buffer, MAX_LEN, file))
		q = parse_line(buffer, q);

	free(buffer);
	return (void*)0;
}

struct question *
parse_line(char *line, struct question *q)
{
	if (line[0] == '#') /* comment lines begin with # */
		return q;

	if (line[0] == '\n') {
		if (!q->text)
			return q; /* no question found yet */
		/* else */
			/* TODO create new question */
	}

	if (!q->text) {
		set_question_text(line, q);
		return q; /* TODO this is temporary */
	} /* else */
		/* append_choice(q, line) */

	printf("TODO parse: %s", line);

	return q;
}

void
set_question_text(char *src, struct question *q)
{
	size_t len;

	len = strlen(src);
	q->text = calloc(len + 1, sizeof(char));
	if (!q->text)
		kill_program("calloc failed: %s\n", src);

	strncpy(q->text, src, len); /* TODO check return value? */
}
