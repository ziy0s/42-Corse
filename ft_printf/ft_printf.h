/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaissi <zaissi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:09:57 by zaissi            #+#    #+#             */
/*   Updated: 2024/12/13 12:56:34 by zaissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_puthex(unsigned long i, char str[16], int s);
int		ft_puthex_x(unsigned int i, char str[16], int s);
int		ft_putu(unsigned int i);
int		ft_bonus(const char *str, int *i, va_list args);
int		ft_put(char s, va_list args);

#endif