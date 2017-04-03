/* This code is licensed under the Unlicense; see LICENSE for details. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pugge.h"
#include "util.h"

static struct question *parse_file(char *filename, struct question *q);
static struct question *parse_line(char *line, struct question *q);
static void             set_question_text(char *src, struct question *q);

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
	if (line[0] == '#') /* ignore comment lines beginning with # */
		return q;

	if (line[0] == '\n') {
		if (q->text) /* current question is completed */
			printf("TODO start new question\n");
		else
			return q; /* question text not started yet */
	}

	if (!q->text)
		set_question_text(line, q);
	else
		printf("TODO append_choice(q, %s", line);

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
	/* TODO don't copy \n  */
	/* TODO export this function? */
}
