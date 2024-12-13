/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:45:24 by zaissi            #+#    #+#             */
/*   Updated: 2024/11/17 10:50:18 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	token_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_token(char **token, size_t i)
{
	while (i > 0)
		free(token[--i]);
	free(token);
}

static char	*allocate(const char *s, size_t len)
{
	char	*token;
	size_t	i;

	token = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!token)
		return (NULL);
	while (i < len)
	{
		token[i] = s[i];
		i++;
	}
	token[len] = '\0';
	return (token);
}

static char	**token_copy(char const *s, char c, char **token, size_t n)
{
	size_t	i;
	int		j;
	int		len;

	i = 0;
	while (*s && i < n)
	{
		j = 0;
		if (*s != c)
		{
			len = token_len(s, c);
			token[i] = allocate(s, len);
			if (token[i] == NULL)
			{
				free_token(token, i);
				return (NULL);
			}
			i++;
			s += len;
		}
		else
			s++;
	}
	token[i] = NULL;
	return (token);
}

char	**ft_split(char const *s, char c)
{
	char			**token;
	char const		*p;
	size_t			i;
	size_t			nbr;

	i = 0;
	nbr = 0;
	if (!s)
		return (NULL);
	p = s;
	while (*s)
	{
		if (*s != c && !i)
		{
			i = 1;
			nbr++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	token = malloc((nbr + 1) * sizeof(char *));
	if (token == NULL)
		return (NULL);
	return (token_copy(p, c, token, nbr));
}

	