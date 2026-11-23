#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	new = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
