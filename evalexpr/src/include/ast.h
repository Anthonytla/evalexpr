#ifndef AST_H
# define AST_H

#include "type.h"
#include "my_getopt.h"

struct ast_node
{
    struct ast_node *rhs;
    struct ast_node *lhs;
    enum type type;
    int value;
};

/**
**      \param      lhs                left child
**      \param      rhs                right child
**      \param      type               type of the new node
**      \param      value              value of the new node
** 
**      \return     allocated node
*/
struct ast_node *ast_node_create(struct ast_node *lhs,
                                 struct ast_node *rhs,
                                 enum type type,
                                 int value);

/**
**      \param      ast                ast to free
*/
void ast_node_destroy(struct ast_node *ast);

/**
**      \param      ast                ast to print 
**      \param      print_type         traversal type
*/
void ast_print(struct ast_node *ast, enum opt_print print_type);

#endif /* AST_H */
