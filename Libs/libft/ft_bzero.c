#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n-- > 0)
	{
		p[0] = '\0';
		p++;
	}
}
