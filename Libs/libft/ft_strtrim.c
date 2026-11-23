#include <stdlib.h>
#include "libft.h"

static size_t	ft_trimstart(char const *s1, char const *set);
static size_t	ft_trimend(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	size;
	size_t	i;

	start = ft_trimstart(s1, set);
	end = ft_trimend(s1, set);
	i = 0;
	size = ft_strlen(s1);
	if (start >= size || size == 0)
	{
		trim = malloc(sizeof(char) * 1);
		trim[0] = '\0';
		return (trim);
	}
	else
		trim = malloc(sizeof(char) * (size - start - end + 1));
	while (i < size - start - end)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}

static size_t	ft_trimstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (set[0] == '\0')
		return (0);
	while (s1[i] != '\0' && j == 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				i++;
				j = 0;
				break ;
			}
			else
				j++;
		}
	}
	return (i);
}

static size_t	ft_trimend(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	if (set[0] == '\0')
		return (0);
	size = ft_strlen(s1) - 1;
	while (i < size && j == 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[size - i] == set[j])
			{
				i++;
				j = 0;
				break ;
			}
			else
				j++;
		}
	}
	return (i);
}
/*
int	main(void)
{
	char str[] = "xxtestxx";
	char set[] = "x";
	char *trimed = ft_strtrim(str, set);
	
	printf("%s", trimed);
}
*/
