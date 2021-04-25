#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct queue *lexer(const char *line, int *error)
{
    struct queue *q = queue_init();
    int i = 0;
    char op[8] = {'+', '-', '*', '/', '%', '^', '(', ')'};
    char *number = calloc(1, 560);
    struct token *t = NULL;
    while (line[i])
    {
        if (line[i] >= '0' && line[i] <= '9')
            number[strlen(number)] = line[i];
        else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' || line[i] == '%' || line[i] == '^' || line[i] == '(' || line[i] == ')')
        {
            number[strlen(number) + 1] = '\0';
            if (number[0] != '\0')
		{
		    t = token_create(8, atoi(number));
		    queue_push(q, t);
		}
	    for (int j = 0; j < 8; j++)
                if (line[i] == op[j])
		    {
			t = token_create(j, 0);
			queue_push(q, t);
		    }
	    size_t a = strlen(number);
	    for (size_t i = 0; i < a; i++)
		number[i] = '\0';
	}
        *error = 0;
        i++;
    }
    if (number[0] != '\0')
	{
	    number[strlen(number) + 1] = '\0';
	    t = token_create(8, atoi(number));
	    queue_push(q, t);
	}
    free(number);
    return q;
}
