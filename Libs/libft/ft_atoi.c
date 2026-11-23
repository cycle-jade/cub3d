int	ft_atoi(const char *nptr)
{
	int	i;
	int	is_negative;
	int	total;

	i = 0;
	is_negative = 0;
	total = 0;
	while ((nptr[i] == '\f') || (nptr[i] == '\n') || (nptr[i] == '\r')
		|| (nptr[i] == '\t') || (nptr[i] == ' ') || (nptr[i] == '\v'))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	while ((nptr[i] > 47) && (nptr[i] < 58))
	{
		total = total * 10;
		total += nptr[i++] - 48;
	}
	if (is_negative != 0)
		total = -total;
	return (total);
}

/*
#include <stdio.h>

int	main(void)
{
	char str[] = " 	  	\r\v 256843x2";
	int	x = ft_atoi(str);

	printf("%d", x);
}
*/
