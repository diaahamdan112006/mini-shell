#include "../include/mini.h"

char	*ft_strjoins(char *save, char *buffer)
{
	int		i;
	int		j;
	char	*strbuffer;
	int		len;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	len = ft_strlen(save) + ft_strlen(buffer);
	strbuffer = (char *)malloc(sizeof(char) * (len + 1));
	if (strbuffer == 0)
		return (NULL);
	if (save)
	{
		while (save[j] && i < len)
			strbuffer[i++] = save[j++];
	}
	j = 0;
	while (buffer[j] && i < len)
		strbuffer[i++] = buffer[j++];
	strbuffer[i] = '\0';
	free(save);
	return (strbuffer);
}
