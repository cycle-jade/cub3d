#include <stdlib.h>

static int	ft_itoa_size(int n);

char	*ft_itoa(int n)
{
	int		str_size;
	int		digit;
	char	*itoa;

	digit = 0;
	str_size = ft_itoa_size(n);
	itoa = (char *)malloc(sizeof(char) * (str_size + 1));
	itoa[str_size] = '\0';
	if (n < 0)
		itoa[0] = '-';
	else if (n == 0)
		itoa[0] = '0';
	while (n != 0)
	{
		digit = n % 10;
		if (digit < 0)
			digit = -digit;
		itoa[str_size - 1] = '0' + digit;
		str_size--;
		n = n / 10;
	}
	return (itoa);
}

static int	ft_itoa_size(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

/*
#include <stdio.h>

int	main(void)
{
	int	x = 40;
	printf("%d\n", ft_itoa_size(x));
	printf("%s", ft_itoa(x));
}
*/
