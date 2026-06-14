#include "../include/parsing.h"

char	*get_prompt_path(t_env *head)
{
	while (head)
	{
		if (!ft_strcmp(head->name, "PWD"))
			return (ft_strdup(head->data));
		head = head->next;
	}
	return (NULL);
}

char	*show_prompt(void)
{
	char	*path;
	char	*input;
	char	*tmp;
	char	*user;
	char	*prompt;
	char	*host;

	path = getcwd(NULL, 0);
	if (!path)
		path = ft_strdup("~");
	user = getenv("USER");
	if (!user)
		user = "diyaa";
	host = getenv("HOSTNAME");
	if (!host)
		host = "MacBook-Pro";
	tmp = ft_strjoin("\033[1;32m", user);
	prompt = ft_strjoin(tmp, "\033[1;37m@");
	free(tmp);
	tmp = prompt;
	prompt = ft_strjoin(tmp, host);
	free(tmp);
	tmp = prompt;
	prompt = ft_strjoin(tmp, " \033[1;34m");
	free(tmp);
	tmp = prompt;
	prompt = ft_strjoin(tmp, path);
	free(tmp);
	tmp = prompt;
	prompt = ft_strjoin(tmp, "\033[1;37m$ \033[0m");
	free(tmp);
	free(path);
	input = readline(prompt);
	free(prompt);
	return (input);
}
