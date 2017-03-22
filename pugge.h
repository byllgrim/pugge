struct question;
union data {
    struct question q;
    char *s;
};

struct node {
    struct node next;
};

struct question {
    char *text;
    char *answer;
    struct node first;
    struct node last;
    /* TODO initialize variables */
};
