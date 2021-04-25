#include "include/parser.h"
#include <stdlib.h>

struct ast_node *parser(struct queue *tokens, int *error)
{
    struct ast_node *res = NULL;
    res = parse_e(tokens);
    *error = 0;
    return res;
}

struct ast_node *parse_e(struct queue *tokens)
{
    struct ast_node *left_child = parse_t(tokens);
    struct token *lookahead = queue_peek(tokens);
    while (lookahead && (lookahead->type == 0 || lookahead->type == 1))
    {
        queue_pop(tokens);
        struct ast_node *right_child = parse_t(tokens);
        left_child = ast_node_create(left_child, right_child, lookahead->type
                                     , lookahead->value);
        lookahead = queue_peek(tokens);
    }
    return left_child;
}

struct ast_node *parse_t(struct queue *tokens)
{
    struct ast_node *left_child = parse_f(tokens);
    struct token *lookahead = queue_peek(tokens);
    while (lookahead && (lookahead->type == 2 || lookahead->type == 3 || lookahead->type == 4))
    {
        queue_pop(tokens);
        struct ast_node *right_child = parse_f(tokens);
        left_child =  ast_node_create(left_child, right_child, lookahead->type
                                     , lookahead->value);
        lookahead = queue_peek(tokens);
    }
    return left_child;
}

struct ast_node *parse_f(struct queue *tokens)
{
    struct token *lookahead = queue_peek(tokens);
    int sign = 1;
    while (lookahead && (lookahead->type == 0 || lookahead->type == 1))
    {
	queue_pop(tokens);
        if (lookahead->type == 0)
            sign = sign * 1      ;
        else
            sign = sign * -1     ;
        lookahead = queue_peek(tokens);
    }
    struct ast_node *right_child = parse_p(tokens);
    if (sign == -1)
	right_child->value = -right_child->value;
    return right_child;
}

struct ast_node *parse_p(struct queue *tokens)
{
    struct ast_node *left_child = parse_g(tokens);
    struct token *lookahead = queue_peek(tokens);
    while (lookahead && lookahead->type == 5)
    {
        queue_pop(tokens);
        struct ast_node *right_child = parse_p(tokens);
        left_child = ast_node_create(left_child, right_child, lookahead->type
                                     , lookahead->value);
        lookahead = queue_peek(tokens);
    }
    return left_child;
}

struct ast_node *parse_g(struct queue *tokens)
{
    struct token *lookahead = queue_peek(tokens);
    struct ast_node *node = NULL;
    if (lookahead->type == 6)
	{
	    queue_pop(tokens);
	    node = parse_e(tokens);
	    queue_pop(tokens);
	}

    else if (lookahead->type == 8)
        node = parse_n(tokens);
    return node;
}

struct ast_node *parse_n(struct queue *tokens)
{
    struct token *lookahead = queue_peek(tokens);
    queue_pop(tokens);
    return ast_node_create(NULL, NULL, 8, lookahead->value);
}
