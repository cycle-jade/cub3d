#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;

	i = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (i < (size_t)ft_strlen(s1))
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < (size_t)ft_strlen(s2))
	{
		join[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	join[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (join);
}

/*
#include <stdio.h>
int	main(void)
{
	char a[] = "this is ";
	char b[] = "the start of something big";

	printf("%s %lu", ft_strjoin(a, b), sizeof(a) + sizeof(b));
}
*/
