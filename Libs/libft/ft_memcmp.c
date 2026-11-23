#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n--)
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
		}
		else
			return (*p1 - *p2);
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char a[] = {1, 8, 7, 3, 7, 2, 4};
	char b[] = {1, 8, 7, 3, 7, 2, 4};

	printf("%d", ft_memcmp(a, b, 0));
}
*/
