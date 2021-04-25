#include "include/ast.h"
#include "include/lexer.h"
#include "include/parser.h"
#include "include/queue.h"
#include "include/token.h"
#include "include/type.h"
#include "include/evalexpr.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main(void)
{
    int error = 0;
    char *line = readline("Enter ");
    struct queue *q = lexer(line, &error);
    queue_print(q);
    struct ast_node *node = parser(q, &error);
    ast_print(node, 0);
    printf("\n");
    int eval = evalexpr(node, &error);
    printf("%d\n", eval);
    free(line);
    queue_destroy(q);
    ast_node_destroy(node);
    return 0;
}
