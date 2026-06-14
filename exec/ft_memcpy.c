#include "../include/mini.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*c_dest;
	unsigned const char	*c_src;

	i = 0;
	c_dest = (unsigned char *)dst;
	c_src = (unsigned const char *)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dst);
}
