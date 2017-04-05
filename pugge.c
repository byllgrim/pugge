/* This code is licensed under the Unlicense; see LICENSE for details. */
#include <stdlib.h>

#include "questions.h" /* must be first of the local includes */
#include "files.h"
#include "utils.h"

int
main(int argc, char **argv)
{
	struct question *q;

	if (argc < 2)
		kill_program("usage: %s <file> ...\n", argv[0]);

	q = parse_all_files(argv + 1);
	(void)q; /* TODO present all Q n A */

	/* TODO take answer number as input */
	/* TODO present correct answer */
	/* TODO optional randomization of question order */
	/* TODO randomization of answer order */
	/* TODO allow #comments in answer text? */
	/* TODO allow "Don't know" as an answer? */

	return 0;
}
