/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:17:49 by null              #+#    #+#             */
/*   Updated: 2020/02/26 21:59:51 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_flags(int d, int u, char *s, char *c, va_list factor)
{
	char **st;
	c++;
	if (*c == 'd')
	{
		d = va_arg(factor, int);
		ft_putnbr(d);
	}
	else if (*c == 's')
	{
		s = va_arg(factor, char *);
		ft_putstr(s);
	}
	else if(*c == 'u')
	{
		u = va_arg(factor, unsigned long);
		ft_putnbr((int)u);
	}
	return (c);
}
void				ft_lprintf(char *format, ...)
{
	int				d;
	unsigned long	u;
	char			*s;
	char			*c = 0;
	va_list			factor;

	va_start(factor, format);
	c = format;
	while (*c)
	{
		if (*c != '%')
		{
			ft_putchar(*c);
			c++;
			continue;
		}
		c++;
		if (*c == '*')
		{

			c++;
		}
		c--;
		c = check_flags(d, u, s, c, factor);
		c++;
	}
	va_end(factor);
}

void	print_table(int d, char *str)
{
	int temp;

	temp = d - ft_strlen(str);
	while (--temp)
		ft_putchar(' ');
	ft_putstr(str);
}

char		*ft_zlprintf(char *format, ...)
{
	int		d;
	int		f;
	char	*s;
	char	*c = 0;
	va_list	factor;

	va_start(factor, format);
	c = format;
	while (*c)
	{
		if (*c != '%')
		{
			ft_putchar(*c);
			c++;
			continue;
		}
		c = check_flags(d, f, s, c, factor);
		c++;
	}
	va_end(factor);
	return (s);
}

char	*zcheck_flags(int d, int f, char *s, char *c, va_list factor)
{
	char *temp;
	c++;
	if (*c == 'd')
	{
		d = va_arg(factor, int);
		temp = ft_itoa(d);
		return (temp);
	}
	else if (*c == 's')
	{
		s = va_arg(factor, char *);
		return (s);
	}
	return (c);
}