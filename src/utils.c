#include "utils.h"

int	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	const unsigned char	*source;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dest);
}

char	*ft_newstr(char *oldstr, char	*newstr)
{
	char	*buffer;
	int		len;

	if (!oldstr && !newstr)
		return (NULL);
	if (!oldstr)
		return (newstr);
	free(oldstr);
	len = ft_strlen(newstr);

	buffer = malloc(len + 1);
	if (!buffer)
		return (NULL);

	ft_memcpy(buffer, newstr, len);
	buffer[len] = '\0';
	return (buffer);
}







