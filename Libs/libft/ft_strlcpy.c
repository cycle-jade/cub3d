#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while ((i < size - 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <stdio.h>
int main(void)
{
	char d[20];
	char s[] = "does this thing even work";

	printf("%lu\n", sizeof(s));
	printf("%zu\n", ft_strlcpy(d, s, 30));
	printf("%s\n", d);
}
*/
