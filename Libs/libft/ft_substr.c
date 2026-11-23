#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	if (len > size - start)
		sub = (char *)malloc(sizeof(char) * (size - start + 1));
	else if (start >= size)
	{
		sub = (char *)malloc(sizeof(char) * 1);
		sub[0] = '\0';
		return (sub);
	}
	else
		sub = (char *)malloc(sizeof(char) * (len + 1));
	while (i < size - start && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
