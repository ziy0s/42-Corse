/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:06:53 by zaissi            #+#    #+#             */
/*   Updated: 2024/12/12 20:45:25 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_pls(va_list args)
{
	int	res;
	int	p;

	res = 0;
	p = va_arg(args, int);
	if (p >= 0)
		res += ft_putchar_fd('+', 1);
	res += ft_putnbr_fd(p, 1);
	return (res);
}

static int	ft_spc(va_list args)
{
	int	ptr;
	int	res;

	res = 0;
	ptr = va_arg(args, int);
	if (ptr >= 0)
		res += ft_putchar_fd(' ', 1);
	res += ft_putnbr_fd(ptr, 1);
	return (res);
}

static void	check(char s, int *pl, int *sp, int *hs)
{
	if (s == ' ')
		*sp = 1;
	else if (s == '+')
		*pl = 1;
	else if (s == '#')
		*hs = 1;
}

static int	ft_hs(va_list arg, const char *str, int *i)
{
	int		p;
	int		res;

	p = va_arg(arg, int);
	res = 0;
	if (str[*i + 1] == 'x' && p)
	{
		res += ft_putstr_fd("0x", 1);
		res += ft_puthex_x(p, "0123456789abcdef", str[*i + 1]);
	}
	else if (str[*i + 1] == 'X' && p)
	{
		res += ft_putstr_fd("0X", 1);
		res += ft_puthex_x(p, "0123456789ABCDEF", str[*i + 1]);
	}
	else
		res += ft_putnbr_fd(p, 1);
	return (res);
}

int	ft_bonus(const char *str, int *i, va_list args)
{
	int	res;
	int	pl;
	int	sp;
	int	hs;

	res = 0;
	pl = 0;
	sp = 0;
	hs = 0;
	while (str[*i + 1] == '+' || str[*i + 1] == '#' || str[*i + 1] == ' ')
	{
		check(str[*i + 1], &pl, &sp, &hs);
		*i += 1;
	}
	if (pl && (str[*i + 1] == 'd' || str[*i + 1] == 'i'))
		res += ft_pls(args);
	else if (sp && (str[*i + 1] == 'd' || str[*i + 1] == 'i'))
		res += ft_spc(args);
	else if (hs && (str[*i + 1] == 'x' || str[*i + 1] == 'X'))
		res += ft_hs(args, str, i);
	else
		res += ft_put(str[*i + 1], args);
	return (res);
}
