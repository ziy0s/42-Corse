/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:18:53 by zaissi            #+#    #+#             */
/*   Updated: 2024/11/06 13:22:32 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*p2;
	t_list	*node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	p2 = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&p2, del);
			return (NULL);
		}
		if (p2 == NULL)
			p2 = node;
		else
			p->next = node;
		p = node;
		lst = lst->next;
	}
	return (p2);
}
