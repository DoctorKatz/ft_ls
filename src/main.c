/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 00:32:51 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/10 00:35:38 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_mnode			*g_memlst;

static void		validate_flag(char *bin, char *s, char *opt)
{
	int			i;

	i = 1;
	while (s[i])
	{
		if (!ft_findchr(OPT_FLGS, s[i]))
		{
			ft_lprintf("%s: illegal option -- %c\n", bin, s[i]);
			ft_lprintf("usage: %s [%s] [file ...]\n", bin, OPT_FLGS);
			return (exit(FLG_ERR));
		}
		else if (!ft_findchr(opt, s[i]))
			ft_strncat(opt, &(s[i]), 1);
		i += 1;
	}
	return ;
}

static t_path	*parse_opt(char *opt, char *flags[], int total)
{
	int			i;
	t_path		*path;

	i = 0;
	path = NULL;
	while (++i < total)
	{
		if (!ft_strcmp(flags[i], "--"))
			i += 1;
		else if (flags[i][0] == '-')
		{
			validate_flag(flags[0], flags[i], opt);
			continue ;
		}
		break ;
	}
	while (++i <= total)
		path = path_add(path, flags[i - 1], opt);
	return (path);
}

int				main(int argc, char *argv[])
{
	t_path		*path;
	char		*opt;
	char		*pnull;

	g_memlst = NULL;
	pnull = NULL;
	ft_push_ptr(&g_memlst, pnull);
	opt = ft_strnew(ft_strlen(OPT_FLGS));
	if (opt)
	{
		path = parse_opt(opt, argv, argc);
		if (!path)
			path = path_add(path, ".", opt);
		path = path_srt(path, opt);
		ft_ls(path, opt);
		path_del(path);
		ft_strdel(&opt);
	}
	ft_memlstdelete(&g_memlst);
	return (!opt ? MEM_ERR : 0);
}
