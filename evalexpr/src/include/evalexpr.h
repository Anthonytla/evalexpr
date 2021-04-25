#ifndef EVALEXPR_H
# define EVALEXPR_H

#include "ast.h"

/**
**      \param      ast                ast to evaluate
**      \param      error              pointer to set the error code 
** 
**      \return     result of evalexpr
*/
int evalexpr(struct ast_node *expr, int *error);

#endif /* EVALEXPR_H */
