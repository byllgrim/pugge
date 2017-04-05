enum {MAX_LEN = 512}; /* maximum length of string buffer TODO rename */

struct question {
	char            *text;    /* text of the question */
	struct answer   *answers; /* start node of linked list of answers */
	struct question *next;    /* next question */
};

struct answer {
	char          *text;    /* answer text */
	char           correct; /* true if correct answer */
	struct answer *next;    /* next answer in linked list */
};

void set_question_text(char *src, struct question *q);
void append_answer(char *line, struct question *q);
