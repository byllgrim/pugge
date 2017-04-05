enum {MAX_LEN = 512}; /* maximum length of string buffer TODO rename */

struct question {
	char            *text;    /* text of the question */
	struct choice   *choices; /* start node of linked list of answers */
	struct question *next;    /* next question */
};

struct choice { /* TODO rename answer? */
	char          *text;    /* answer text */
	char           correct; /* true if correct answer */
	struct choice *next;    /* next answer in linked list */
};

void set_question_text(char *src, struct question *q);
