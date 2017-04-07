#include <stdio.h>
#include "questions.h"

void start_quiz(struct question *q){
    for (; q; q=q->next)
        printf("%s\n", q->text);

}
