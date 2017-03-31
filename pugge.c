/* This code is licensed under the Unlicense; see LICENSE for details. */

#include "pugge.h" /* must be first of the local includes */
#include "file_handling.h"

int
main(int argc, char **argv)
{
	(void)argc; /* TODO usage function */

	parse_all_files(argv + 1);
	/*
	 * TODO:
	 * Take answer choice as input.
	 * Present correct answer.
	 * Optional randomization of question order.
	 * Randomization of choice order.
	 * Allow for variable number of answer choices.
	 * Allow #comments in question file.
	 * Allow "Don't know" as an option?
	 */

	return 0;
}
