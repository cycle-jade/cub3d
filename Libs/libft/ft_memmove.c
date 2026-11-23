#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ps;
	unsigned char	tmp[1];
	unsigned char	*pd;
	size_t			i;

	i = 0;
	ps = (unsigned char *)src;
	pd = (unsigned char *)dest;
	if (ps > pd)
	{
		while (i < n)
		{
			*tmp = ps[i];
			pd[i++] = *tmp;
		}
	}
	else
	{
		while (n--)
		{
			*tmp = ps[n];
			pd[n] = *tmp;
		}
	}
	return (pd);
}
