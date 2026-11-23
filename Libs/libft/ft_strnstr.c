#include <string.h>

static int	ft_is_included_in_n(char *s1, char *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*pb;
	size_t	i;

	i = 0;
	pb = (char *)big;
	if (little[0] == '\0')
		return ((char *)big);
	while ((i < len) && (big[i] != '\0'))
	{
		if (ft_is_included_in_n(pb, (char *)little, len - i) != 0)
			return (pb);
		else
		{
			pb++;
			i++;
		}
	}
	return (NULL);
}

static int	ft_is_included_in_n(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == s2[i])
		{
			i++;
			if (s2[i] == '\0')
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	char str1[] = "it is what it is";
	char str2[] = "is";
	printf("%lu\n", sizeof(str1));
	char *ret = ft_strnstr(str1, str2, -1);
	if (ret != NULL)
		printf("%s\n", ret);
	else
		printf("NULL");
}
*/
