#include "../include/mini.h"

int	ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while ((s[i] != '\0') && (s[i] != (char)c))
	{
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}
