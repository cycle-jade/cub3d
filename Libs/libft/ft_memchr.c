#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while ((s != NULL) && (n--))
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		else
			ptr++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main(void)
{
	char s[] = {0, 1, 2, 3, 4, 5};
	char	*p;

	p = ft_memchr(s, 2 + 256 , 3);
	//printf("%ld\n", p -s +1);
	if(p == s + 2)
		printf("OK");
}
*/
