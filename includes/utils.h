#ifndef	UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_newstr(char *oldstr, char	*newstr);
void	*ft_memcpy(void *dest, const void *src, size_t n);


#endif