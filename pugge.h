enum {MAX_LEN = 512};

struct question {
	char            *text;
	struct choice   *choices;
	struct question *next;
	/* TODO initialize variables? */
};

struct choice {
	char          *text;
	char           right; /* TODO comment on correct chocie */
	struct choice *next;
};
