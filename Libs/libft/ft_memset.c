#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = s;
	while (n-- > 0)
	{
		p[0] = c;
		p++;
	}
	return (s);
}

/*
#include <stdio.h>
int	main(void)
{
	char	x[] = "i hope this works";
	printf("%p\n", &x);
	ft_memset(&x, 'y', 4);
	printf("%s", x);
}
*/
