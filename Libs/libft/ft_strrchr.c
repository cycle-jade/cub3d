#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*l;

	c = (char) c;
	l = NULL;
	while (*s != '\0')
	{
		if (*s == c)
		{
			l = s;
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	else
		return ((char *)l);
}

/*
#include <stdio.h>

int main(void)
{
	char str[] = "testing upon testing";
	char *ret = ft_strrchr(str, 't');

	printf("%s", ret);
}
*/
