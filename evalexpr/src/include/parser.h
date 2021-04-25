#ifndef PARSER_H
# define PARSER_H

#include "ast.h"
#include "queue.h"
#include "token.h"

/**
**      \param      tokens               queue of tokens
**      \param      error                pointer to set error code
** 
**      \return     resulting ast_node with all tokens
*/
struct ast_node *parser(struct queue *tokens, int *error);
struct ast_node *parse_e(struct queue *tokens);
struct ast_node *parse_t(struct queue *tokens);
struct ast_node *parse_f(struct queue *tokens);
struct ast_node *parse_p(struct queue *tokens);
struct ast_node *parse_g(struct queue *tokens);
struct ast_node *parse_n(struct queue *tokens);

#endif /* PARSER_H */
