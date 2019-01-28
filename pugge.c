#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {RDBUFLEN = 512};

struct question {
    char *text;
    struct answer *answers;
    struct question *next;
};

struct answer {
    char *text;
    int correct;
    struct answer *next;
};

static void
kill_program(char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    vfprintf(stderr, format, ap);
    va_end(ap);

    exit(EXIT_FAILURE);
}

static void *
xcalloc(size_t n, size_t size)
{
    void *p;

    if (!n)
        kill_program("xcalloc: can't allocate 0 bytes");

    p = calloc(n, size);
    if (!p)
        kill_program("xcalloc: failed to allocate");

    return p;
}

static void
set_question_text(char *src, struct question *q)
{
    size_t len;

    len = strlen(src);
    q->text = xcalloc(len, sizeof(char));

    strncpy(q->text, src, len);
    q->text[len - 1] = '\0';

}

static void
append_answer(char *src, struct question *q)
{
    struct answer *a;
    size_t len;

    if (!q->answers)
        q->answers = xcalloc(1, sizeof(q->answers));

    for (a = q->answers; a->text; a = a->next)
        if (!a->next)
            a->next = xcalloc(1, sizeof(q->answers));

    len = strlen(src);

    if (src[0] == '!') {
        a->correct = 1;
        src++;
        len--;
    }

    a->text = xcalloc(len, sizeof(char));
    strncpy(a->text, src, len);
    a->text[len - 1] = '\0';
}

struct answer *
get_answer(struct question *q, int n)
{
    struct answer *a;
    int i;

    a = q->answers;
    for (i = 1; a && i < n; i++)
        a = a->next;

    return a;
}

static int
get_choice(void)
{
    char *s;
    int i;

    s = xcalloc(BUFSIZ + 1, sizeof(*s));
    printf("Choice: ");
    fgets(s, BUFSIZ, stdin);
    i = atoi(s);
    free(s);
    return i;
}

static char *
get_correct(struct question *q)
{
    struct answer *ans;

    for (ans = q->answers; ans; ans = ans->next)
        if (ans->correct)
            return ans->text;

    return 0;
}

static void
verify_choice(struct question *q, int c)
{
    char *ans;

    while (!c ) {
        printf("Please choose a valid number\n");
        c = get_choice();
    }

    if (get_answer(q, c)->correct) {
        printf("Congratulations!!!!");
    } else {
        ans = get_correct(q);
        printf("The right answer is %s", ans);
    }

    getchar();
}

static void
start_quiz(struct question *q)
{
    struct answer *a;
    int i, c;

    for (; q; q=q->next) {
        printf("%s\n", q->text);
        for (i = 1, a = q->answers; a; a = a->next, i++)
            printf("%d) %s\n", i, a->text);
        c = get_choice();
        verify_choice(q, c);
    }
}

struct question *
parse_line(char *line, struct question *q)
{
    if (line[0] == '#')
        return q;

    if (line[0] == '\n') {
        if (q->text)
            return q->next = xcalloc(1, sizeof(q));
        else
            return q;
    }

    if (!q->text)
        set_question_text(line, q);
    else
        append_answer(line, q);

    return q;
}

struct question *
parse_file(char *filename, struct question *q)
{
    FILE *file;
    char *buffer;

    file = fopen(filename, "r");
    if (!file)
        kill_program("file not found: %s\n", filename);

    buffer = xcalloc(RDBUFLEN, sizeof(char));
    while (fgets(buffer, RDBUFLEN, file))
        q = parse_line(buffer, q);

    free(buffer);
    return (void*)0;
}

struct question *
parse_all_files(char **files)
{
    int i;
    struct question *first, *last;

    first = last = xcalloc(1, sizeof(first));

    for (i = 0; files[i]; i++)
        last = parse_file(files[i], last);

    return first;
}

int
main(int argc, char **argv)
{
    struct question *q;

    if (argc < 2)
        kill_program("usage: %s <file> ...\n", argv[0]);

    q = parse_all_files(argv + 1);
    start_quiz(q);

    return EXIT_SUCCESS;
}
