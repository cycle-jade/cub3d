#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		else
		{
			s++;
		}
	}
	if (*s == '\0' && c == 0)
		return ((char *)s);
	else
		return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	char str[] = "testing upon testing";
	char *ret = ft_strchr(str, 'z');
	
	printf("%s", ret);
}
*/
