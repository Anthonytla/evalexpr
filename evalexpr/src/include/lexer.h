#ifndef LEXER_H
#define LEXER_H

#include "queue.h"
#include "my_getopt.h"



/**
**      \param      line               readed line 
**      \param      options            options for eval-expr
**      \param      error              pointer to set the error code 
** 
**      \return     queue of tokens
*/
struct queue *lexer(const char *line, int *error);

#endif /* LEXER_H */
