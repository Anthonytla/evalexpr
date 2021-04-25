#include <stddef.h>

#include "ast.h"

struct ast_node *basic_addition_tree(void)
{
    struct ast_node *a = ast_node_create(NULL, NULL, NUM, 2);
    struct ast_node *b = ast_node_create(NULL, NULL, NUM, 8);

    return ast_node_create(a, b, PLUS, 0);
}

struct ast_node *basic_mult_tree(void)
{
    struct ast_node *a = ast_node_create(NULL, NULL, NUM, 2);
    struct ast_node *b = ast_node_create(NULL, NULL, NUM, 3);
    struct ast_node *c = ast_node_create(NULL, NULL, NUM, 4);

    struct ast_node *mul = ast_node_create(b, c, MUL, 0);

    return ast_node_create(a, mul, PLUS, 0);
}

struct ast_node *basic_pow_tree(void)
{
    struct ast_node *a = ast_node_create(NULL, NULL, NUM, 2);
    struct ast_node *b = ast_node_create(NULL, NULL, NUM, 3);

    return ast_node_create(a, b, POW, 0);
}

struct ast_node *priority_pow_tree(void)
{
    struct ast_node *a = ast_node_create(NULL, NULL, NUM, 2);
    struct ast_node *b = ast_node_create(NULL, NULL, NUM, 3);
    struct ast_node *c = ast_node_create(NULL, NULL, NUM, 4);

    struct ast_node *mul = ast_node_create(b, c, MUL, 0);

    return ast_node_create(a, mul, POW, 0);
}

struct ast_node *tree_example(void)
{
    struct ast_node *a = ast_node_create(NULL, NULL, NUM, 2);
    struct ast_node *b = ast_node_create(NULL, NULL, NUM, 3);
    struct ast_node *c = ast_node_create(NULL, NULL, NUM, 8);
    struct ast_node *d = ast_node_create(NULL, NULL, NUM, 4);

    struct ast_node *mul = ast_node_create(a, b, MUL, 0);
    struct ast_node *div = ast_node_create(c, d, DIV, 0);

    return ast_node_create(mul, div, PLUS, 0);
}
