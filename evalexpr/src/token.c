#include "include/token.h"
#include <stdlib.h>
#include <err.h>
#include <stdio.h>

struct token *token_create(enum type type, int value)
{
    struct token *new = calloc(1, sizeof(struct token));
    new->type = type;
    new->value = value;
    return new;
}

void token_print(struct token *t)
{
    if (t->type == 0)
        printf("%s","PLUS");
    else if (t->type == 1)
        printf("%s","MINUS");
    else if (t->type == 2)
        printf("%s","MUL");
    else if (t->type == 3)
        printf("%s","DIV");
    else if (t->type == 4)
        printf("%s","MOD");
    else if (t->type == 5)
        printf("%s","POW");
    else if (t->type == 6)
        printf("%s","(");
    else if (t->type == 7)
        printf("%s",")");
    else if (t->type == NUM)
        printf("VAL: %d", t->value);
    else
        err(2, "Token non recognize");
}

