#include <stdlib.h>
#include "libft.h"

static size_t	ft_wordcount(char const *s, char c);
static char		*ft_nextword(char const *s, char c, size_t start);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	w;
	char	*nxt;
	char	**tab;

	i = 0;
	w = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	while (s[i] == c && *s)
		i++;
	while (w < ft_wordcount(s, c))
	{
		nxt = ft_nextword(s, c, i);
		tab[w++] = ft_strdup(nxt);
		i += ft_strlen(nxt);
		free(nxt);
		while (s[i] == c)
			i++;
	}
	tab[w] = NULL;
	return (tab);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	wc;
	size_t	i;

	i = 1;
	wc = 1;
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			wc++;
		i++;
	}
	if (s[i - 1] == c)
		wc--;
	return (wc);
}

static char	*ft_nextword(char const *s, char c, size_t start)
{
	char	*word;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[start + size] != '\0' && s[start + size] != c)
		size++;
	word = (char *)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
