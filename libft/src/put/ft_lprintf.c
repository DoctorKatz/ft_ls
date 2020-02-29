/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:54:29 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/01 01:55:41 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*check_flags(int d, char *s, char *c, va_list factor)
{
	char	**st;

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
	else if (*c == 'u')
	{
		d = va_arg(factor, unsigned long);
		ft_putnbr((int)d);
	}
	return (c);
}

void				ft_lprintf(char *format, ...)
{
	int				d;
	unsigned long	u;
	char			*s;
	char			*c;
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
		c = check_flags(d, s, c, factor);
		c++;
	}
	va_end(factor);
}

void				print_table(int d, char *str)
{
	int	temp;

	temp = d - ft_strlen(str);
	while (--temp > 0)
		ft_putchar(' ');
	ft_putstr(str);
}

char				*zcheck_flags(int d, char *s, char *c, va_list factor)
{
	char	*temp;

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

char				*ft_zlprintf(char *format, ...)
{
	t_print			t_values;
	va_list			factor;
	static char		str[256];
	int				i;

	va_start(factor, format);
	t_values.c = format;
	ft_strclr(str);
	while (*(t_values.c))
	{
		i = ft_strlen(str);
		if (*(t_values.c) != '%')
		{
			str[i] = *(t_values.c);
			str[++i] = '\0';
			t_values.c++;
			continue;
		}
		ft_strcat(str, zcheck_flags(t_values.d,\
			t_values.s, t_values.c, factor));
		t_values.c += 2;
	}
	va_end(factor);
	return (str);
}
