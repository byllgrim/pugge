/* This code is licensed under the Unlicense; see LICENSE for details. */
#include <stdio.h>
#include <stdlib.h>

#include "pugge.h"
#include "util.h"
/* TODO should include file_handling.h? */

struct question *parse_file(char *filename, struct question *q);
struct question *parse_line(char *line, struct question *q);

struct question *
parse_all_files(char **files)
{
	int i;
	struct question *first_question, *last_question;
	/* TODO rename first_q? */

	first_question = calloc(1, sizeof(first_question));
	last_question = first_question;
	if (!first_question)
		kill_program("parse_all_files: calloc failed\n");

	for (i=0; files[i]; i++)
		last_question = parse_file(files[i], last_question);

	return first_question;
}

struct question *
parse_file(char *filename, struct question *q)
{
	FILE *file;
	char *buffer;

	file = fopen(filename, "r");
	if (!file)
		kill_program("file not found: %s\n", filename);

	buffer = calloc(MAX_LEN, sizeof(char)); /* TODO MAXLEN + 1 ? */
	while (fgets(buffer, MAX_LEN, file))
		q = parse_line(buffer, q); /* TODO remove newline? */

	free(buffer);
	return (void*)0;
}

struct question *
parse_line(char *line, struct question *q)
{
	printf("TODO parse: %s", line); /* TODO implement function */

	return q;
}
