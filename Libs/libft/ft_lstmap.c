#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	newlst = ft_lstnew((*f)(lst->content));
	if (newlst == NULL)
		return (NULL);
	tmp = newlst;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew((*f)(lst->content));
		if (!(tmp->next))
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (newlst);
}
