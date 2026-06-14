#include "../include/mini.h"

void	ft_set(long *i, unsigned long long *nbr, long *n)
{
	*i = 0;
	*nbr = 0;
	*n = 1;
}

long long	ft_atoi(const char *str)
{
	long						i;
	long						n;
	unsigned long long			nbr;

	ft_set(&i, &nbr, &n);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return ((long long) nbr * n);
}
