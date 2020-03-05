/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:54:29 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/05 21:23:19 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern t_mnode		*g_memlst;

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
	while (--temp)
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
		ft_push_ptr(&g_memlst, temp);
		return (temp);
	}
	else if (*c == 's')
	{
		s = va_arg(factor, char *);
		return (s);
	}
	else if (*c == 'm')
	{
		s = va_arg(factor, char *);
		temp = ft_strrchr(s, ':');
		*temp = '\0';
		return (s);
	}
	return (c);
}

char				*ft_zlprintf(char *format, ...)
{
	t_print			t_values;
	va_list			factor;
	int				i;
	char 			*str;

	str = (char*)malloc(sizeof(char) * 256);
	*str = '\0';
	ft_push_ptr(&g_memlst, str);
	va_start(factor, format);
	t_values.c = format;
	ft_strclr(t_values.str);
	while (*(t_values.c))
	{
		i = ft_strlen(t_values.str);
		if (*(t_values.c) != '%')
		{
			t_values.str[i] = *(t_values.c);
			t_values.str[++i] = '\0';
			t_values.c++;
			continue;
		}
		ft_strcat(t_values.str, zcheck_flags(t_values.d,\
			t_values.s, t_values.c, factor));
		t_values.c += 2;
	}
	ft_strcat(str, t_values.str);
	va_end(factor);
	return (str);
}