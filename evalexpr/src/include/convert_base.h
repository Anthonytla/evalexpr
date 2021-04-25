#ifndef CONVERT_BASE_H
#define CONVERT_BASE_H



/**
**      \param      str                string
**      \param      base               base of str
** 
**      \return     int from string after conversion
*/
int my_atoi_base(const char *str, const char *base);

/**
**      \param      i                  int 
**      \param      base               base of i
** 
**      \return     string from int after conversion
*/
char *my_itoa_base(int i, const char *base);

#endif /* CONVERT_BASE_H */
