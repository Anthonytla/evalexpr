#include "include/ast.h"
#include <stdio.h>
#include <stdlib.h>

struct ast_node *ast_node_create(struct ast_node *lhs,
                                 struct ast_node *rhs,
                                 enum type type,
                                 int value)
{
    struct ast_node *new = calloc(1, sizeof(struct ast_node));
    new->rhs = rhs;
    new->lhs = lhs;
    new->type = type;
    new->value = value;
    return new;
}

void ast_node_destroy(struct ast_node *ast)
{
    if (ast)
    {
        ast_node_destroy(ast->lhs);
        ast_node_destroy(ast->rhs);
    }
    free(ast);
}

void ast_print(struct ast_node *ast, enum opt_print print_type)
{
    if (ast == NULL)
        return;

    /* first recur on left child */
    //ast_print(ast->lhs, print_type);
    /* then print the data of node */
    if (ast->type == 0)
        printf("%c", '+');
    else if (ast->type == 1)
        printf("%c", '-');
    else if (ast->type == 2)
        printf("%c", '*');
    else if (ast->type == 3)
        printf("%c", '/');
    else if (ast->type == 4)
        printf("%c", '%');
    else if (ast->type == 5)
        printf("%c", '^');
    else if (ast->type == 6)
        printf("%c", '(');
    else if (ast->type == 7)
        printf("%c", ')');
    else if (ast->type == 8)
        printf("%d", ast->value);
    ast_print(ast->lhs, print_type);
    /* now recur on right child */
    ast_print(ast->rhs, print_type);
}
