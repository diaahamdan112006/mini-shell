#include "../include/mini.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (src[i] != '\0')
		i++;
	if (dstsize == '\0')
		return (i);
	while (src[c] != '\0' && c < dstsize - 1)
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = '\0';
	return (i);
}
