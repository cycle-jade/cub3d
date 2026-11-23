#include <string.h>

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	char	*ps;
	char	*pd;

	pd = dest;
	ps = src;
	while (n--)
	{
		pd[0] = ps[0];
		pd++;
		ps++;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
		char	d[] = "84345wewfw";
		char	s[] = "world";
		printf("%s\n", d);
		printf("%lu\n", sizeof(s));
		//ft_memcpy(d, s, sizeof(s));
		memcpy(d, s, sizeof(s));
		printf("%s", d);
}
*/
