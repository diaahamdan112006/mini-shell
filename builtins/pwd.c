#include "../include/mini.h"

void	ft_pwd(t_env **env_v)
{
	char	buffer[1024];
	t_env	*new;

	if (getcwd(buffer, 1024))
	{
		printf("%s\n", buffer);
		g_global.get_nb_status = 0;
	}
	else if (getcwd(buffer, 1024) == NULL)
	{
		new = search_element(env_v, "PWD");
		if (!new)
			return ;
		printf("%s\n", new->data);
		g_global.get_nb_status = 0;
	}
}
