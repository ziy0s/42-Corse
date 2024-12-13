/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:54:53 by zaissi            #+#    #+#             */
/*   Updated: 2024/11/08 15:58:01 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_int(int c)
{
	int	i;

	i = 0;
	while (c != 0)
	{
		c /= 10;
		i++;
	}
	return (i);
}

static char	*token(char *p, int i, int n)
{
	while (n != 0 && i >= 0)
	{
		p[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (p);
}

static char	*zero(int n)
{
	char	*p;
	int		check;
	int		i;

	check = 0;
	if (n < 0)
	{
		n = n * -1;
		check = 1;
	}
	i = count_int(n);
	p = malloc(i + 1 + check);
	if (p == NULL)
		return (NULL);
	if (check == 1)
	{
		p[0] = '-';
		i++;
	}
	p[i] = '\0';
	i--;
	return (token(p, i, n));
}

char	*ft_itoa(int n)
{
	char	*p;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
	{
		p = malloc(2);
		if (p == NULL)
			return (NULL);
		p[0] = 48;
		p[1] = '\0';
		return (p);
	}
	p = zero(n);
	return (p);
}
