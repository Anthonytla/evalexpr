#ifndef TREE_EX_H
# define TREE_EX_H

/*
** expr: 2 + 8
** res: 10
*/
struct ast_node *basic_addition_tree(void);

/*
** expr: 2 + 3 * 4
** res: 14
*/
struct ast_node *basic_mult_tree(void);

/*
** expr: 2 ^ 3
** res: 8
*/
struct ast_node *basic_pow_tree(void);

/*
** expr: 2 ^ (3 * 4) 
** res: 4096
*/
struct ast_node *priority_pow_tree(void);

/*
** expr: 2 * 3 + 8 / 4
** res: 8
*/
struct ast_node *tree_example(void);

#endif /* TREE_EX_H */
