#include "include/evalexpr.h"
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <math.h>

int evalexpr(struct ast_node *expr, int *error)
{
    int nb = 0;
    if (expr->type == 8)
        return expr->value;
    else
    {
        struct ast_node *right = expr->rhs;
        struct ast_node *left = expr->lhs;
        if (expr->type == 0)
            nb +=  evalexpr(right, error) + evalexpr(left, error);
        else if (expr->type == 1)
            nb +=  evalexpr(left, error) - evalexpr(right, error);
        else if (expr->type == 2)
            nb +=  evalexpr(left, error) * evalexpr(right, error);
        else if (expr->type == 3)
        {
            if (!right->value)
                err(2,"Division by 0");
            nb +=  evalexpr(left, error) / evalexpr(right, error);
        }
        else if (expr->type == 4)
        {
            nb += evalexpr(left, error) % evalexpr(right, error);
        }
        else if (expr->type == 5)
            nb += pow(evalexpr(left, error), evalexpr(right, error));
    }
    *error = 0;
    return nb;
}
