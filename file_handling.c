/* This code is licensed under the Unlicense; see LICENSE for details. */
#include <stdio.h>
#include <stdlib.h>

#include "pugge.h"
#include "util.h"
/* TODO should include file_handling.h? */

struct question *parse_file(char *filename);

struct question *
parse_all_files(char **files)
{
	int i;

	(void)files; /* TODO implement function */

	for (i=0; files[i]; i++){
		parse_file(files[i]);
	}
	return (void*)0; /* TODO implement function */
}
struct question *
parse_file(char *filename)
{
	FILE *file;
	char *buffer;
	struct question q; /* TODO rename */

	file = fopen(filename, "r");
	if (!file)
		kill_program("file not found: %s\n", filename);

	buffer = calloc(MAX_LEN, sizeof(char)); /* TODO MAXLEN + 1 ? */
	while (fgets(line, MAX_LEN, file))
		q = parse_line(buffer, q); //TODO remove newline?

	free(buffer);
	return (void*)0;
}
