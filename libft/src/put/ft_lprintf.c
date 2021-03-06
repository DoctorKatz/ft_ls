/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:54:29 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/10 01:34:52 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern t_mnode		*g_memlst;

char				*check_flags(int d, char *s, char *c, va_list factor)
{
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
	char			*s;
	char			*c;
	va_list			factor;

	va_start(factor, format);
	c = format;
	d = 0;
	s = NULL;
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
	t_print			t_val;
	va_list			factor;
	int				i;

	t_val.pstr = ft_strnewnull(t_val.pstr);
	ft_push_ptr(&g_memlst, t_val.pstr);
	va_start(factor, format);
	t_val.c = format;
	ft_strclr(t_val.str);
	while (*(t_val.c))
	{
		i = ft_strlen(t_val.str);
		if (*(t_val.c) != '%')
		{
			t_val.str[i] = *(t_val.c);
			t_val.str[++i] = '\0';
			t_val.c++;
			continue;
		}
		ft_strcat(t_val.str, zcheck_flags(t_val.d, t_val.s, t_val.c, factor));
		t_val.c += 2;
	}
	ft_strcat(t_val.pstr, t_val.str);
	va_end(factor);
	return (t_val.pstr);
}
