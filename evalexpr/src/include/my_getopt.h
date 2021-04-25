#ifndef MY_GETOPT_H
#define MY_GETOPT_H

#define DEFAULT_BASE    "0123456789"
#define DEFAULT_OPR     "+-*/%^()" 
#define OPR_LEN         8

enum opt_print
{
    NONE,
    PREFIX,
    SUFFIX,
    INFIX
};

struct opt
{
    char *base;
    char *opr;
    int lexer;
    enum opt_print print;
    int help;
};

/**
**      \param      argc               the number of elements in argv 
**      \param      argv               argv
**      \param      error              pointer to set the error code 
** 
**      \return     options for evalexpr
*/
struct opt *my_getopt(int argc, char **argv, int *error);

/**
**      \param      o              options for evalexpr
*/
void destroy_opt(struct opt *o);

#endif /* MY_GETOPT_H */
