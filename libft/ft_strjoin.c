/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:06:02 by zaissi            #+#    #+#             */
/*   Updated: 2024/11/12 13:14:17 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*return_value(char const *s1, char const *s2, char *p)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		p[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		p[j] = s2[i];
		i++;
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	i = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
	p = malloc(i + 1);
	if (p == NULL)
		return (NULL);
	return (return_value(s1, s2, p));
}
