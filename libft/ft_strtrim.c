/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:46:18 by zaissi            #+#    #+#             */
/*   Updated: 2024/11/15 15:45:24 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_s(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			return (i);
		i++;
	}
	return (i);
}

static size_t	get_e(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (0);
	while (i > 0)
	{
		if (!ft_strchr(set, s1[i]))
			return (i);
		i--;
	}
	if (s1[i] && !ft_strchr(set, s1[i]))
		return (i);
	return (0);
}

static char	*get_token(char const *s1, size_t start, size_t end, char *p)
{
	size_t	i;

	i = 0;
	if (start > end || start >= ft_strlen(s1))
	{
		p[0] = '\0';
		return (p);
	}
	if (end >= ft_strlen(s1))
		end = ft_strlen(s1) - 1;
	while (start <= end)
	{
		p[i] = s1[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	i;
	size_t	k;
	size_t	start;
	size_t	end;

	i = 0;
	k = 0;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = get_s(s1, set);
	end = get_e(s1, set);
	if (start > end)
		return (ft_strdup("\0"));
	k = end - start + 1;
	p = malloc(k + 1);
	if (p == NULL)
		return (NULL);
	return (get_token(s1, start, end, p));
}
