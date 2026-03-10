/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/26 16:36:47 by ekramer       #+#    #+#                 */
/*   Updated: 2026/01/24 03:32:48 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
			return (ft_lstclear(&start, del), NULL);
		ft_lstadd_back(&start, node);
		lst = lst->next;
	}
	return (start);
}
