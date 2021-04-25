#ifndef STRING_H
# define STRING_H

#include <stddef.h>

/**
**      \param      s                    string to evaluate
** 
**      \return     length of the string
*/
size_t my_strlen(const char *s);

/**
**      \param      s1                   first string 
**      \param      s2                   second string
** 
**      \return     result of the comparison
*/
int my_strcmp(const char *s1, const char *s2);

/**
**      \param      s                    string
** 
**      \return     pointer to the allocated memory
*/
char *my_strdup(const char *s);


/**
**      \param      dest                 string
**      \param      src                  string to be appended to dest
** 
**      \return     pointer on the resulting string (dest)
*/
char *my_strcat(char *dest, const char *src);

#endif /* !STRING_H */
