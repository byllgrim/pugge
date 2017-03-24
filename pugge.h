enum {MAX_LEN = 512};

struct question {
	char            *text;
	struct choice   *choices;
	struct question *next;
};

struct choice {
	char          *text;
	char           correct;
	struct choice *next;
};
