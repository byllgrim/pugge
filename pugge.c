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
	(void)q; /* TODO present as answers */

	/*
	 * TODO:
	 * Take answer choice as input.
	 * Present correct answer.
	 * Optional randomization of question order.
	 * Randomization of choice order.
	 * Allow for variable number of answer choices.
	 * Allow #comments in answer choice?
	 * Allow "Don't know" as an option?
	 */

	return 0;
}
