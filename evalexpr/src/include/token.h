#ifndef TOKEN_H
# define TOKEN_H

#include "type.h"

struct token
{
    enum type type;
    int value;
};

/**
**      \param      type            token type 
**      \param      value           token value
** 
**      \return     token struct with its type and value
*/
struct token *token_create(enum type type, int value);

/**
**      \param      t               token to print
*/
void token_print(struct token *t);

#endif /* TOKEN_H */
