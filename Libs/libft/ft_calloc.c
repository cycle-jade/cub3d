#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	if (nmemb == 0 || size == 0)
	{
		p = malloc(1);
		return (p);
	}
	else if (nmemb > 2147483647 || size > 2147483647
		|| nmemb * size > 2147483647)
		return (NULL);
	else
	{
		p = malloc(nmemb * size);
		ft_bzero(p, (nmemb * size));
		return (p);
	}
}
