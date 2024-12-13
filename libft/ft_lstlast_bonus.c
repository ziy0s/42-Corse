/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:38:02 by zaissi            #+#    #+#             */
/*   Updated: 2024/11/08 15:58:42 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	max;

	i = 0;
	if (lst == NULL)
		return (NULL);
	max = ft_lstsize(lst);
	while (i < max - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
