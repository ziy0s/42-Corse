/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:10:22 by zaissi            #+#    #+#             */
/*   Updated: 2024/11/15 17:32:02 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*p;
	char	*s;
	size_t	i;

	i = 0;
	p = dst;
	s = (char *)src;
	if (p < s)
	{
		while (i < len)
		{
			p[i] = s[i];
			i++;
		}
	}
	else if (p > s)
	{
		i = len;
		while (i > 0)
		{
			p[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dst);
}
