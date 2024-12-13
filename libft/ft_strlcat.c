/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:55:48 by zaissi            #+#    #+#             */
/*   Updated: 2024/11/15 15:45:12 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[i] && i < dstsize)
		i++;
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	j = 0;
	len = i;
	while (len < dstsize - 1 && src[j])
	{
		dst[len] = src[j];
		j++;
		len++;
	}
	dst[len] = '\0';
	return (i + ft_strlen(src));
}
