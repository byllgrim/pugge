struct choice {
	char          *text;
	char           right;
	struct choice *next;
};

struct question {
	char            *text;
	struct choice   *choices;
	struct question *next;
	/* TODO initialize variables? */
};
