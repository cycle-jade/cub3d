#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lend;
	size_t	lens;

	i = 0;
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (size >= lend + 1)
	{
		while (src[i] != '\0' && i < size - lend - 1)
		{
			dst[lend + i] = src[i];
			i++;
		}
		dst[lend + i] = '\0';
		return (lend + lens);
	}
	else
		return (size + lens);
}

/*
#include <stdio.h>
int	main(void)
{
	char s[] = "AAAAAAAAA";
	char d[] = "CCCCC";

	printf("%lu\n", sizeof(d));
	printf("%zu\n", ft_strlcat(d, s, -1));
	printf("%s", d);
}
*/
