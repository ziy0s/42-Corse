/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:47:26 by zaissi            #+#    #+#             */
/*   Updated: 2024/11/17 20:42:10 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*p;

	i = count * size;
	if (size != 0 && count != i / size)
		return (NULL);
	p = malloc(i);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, i);
	return (p);
}
