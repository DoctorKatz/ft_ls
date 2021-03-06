/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 00:32:51 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/10 00:32:51 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Print as list if the opt flag is `g` or `l`.
** Else, print by name.
*/

static void		select_print(char *opt, t_file *file, char *path, int type)
{
	if (file)
		ft_findchr(opt, 'g') || ft_findchr(opt, 'l') \
			? print_list(file, path, opt, type) : print_name(file);
	return ;
}

/*
** Prints the files from a given path.
** Calls itself when the opt flag is recursive.
*/

static void		ls(char *path, int type, char *opt, int count)
{
	t_file		*file;

	if (count && type != 2)
		ft_lprintf("%s:\n", path);
	file = create_file(path, opt, type);
	select_print(opt, file, path, type);
	while (file && ft_findchr(opt, 'R'))
	{
		if (ft_strcmp(".", file->name) && ft_strcmp("..", file->name) \
			&& file->type == 4)
		{
			ft_lprintf("\n");
			if (!ft_strcmp("/", path))
				ls(ft_zlprintf("%s%s", path, file->name), 1, opt, count + 1);
			else
				ls(ft_zlprintf("%s/%s", path, file->name), 1, opt, count + 1);
		}
		file = file_del(file);
	}
	return ;
}

/*
** Returns the symbolic link list count.
*/

static int		list_symlnk(t_path *path, char *opt)
{
	int			i;
	int			sym_lnk;
	t_path		*tmp;

	i = 0;
	sym_lnk = 0;
	tmp = path;
	while (tmp)
	{
		if (tmp->type == SYM_PATH)
		{
			ls(tmp->name, tmp->type, opt, i);
			i += 1;
			sym_lnk += 1;
		}
		tmp = tmp->next;
	}
	return (sym_lnk);
}

/*
** From a given path list the different files.
*/

void			ft_ls(t_path *path, char *opt)
{
	int			sym_lnk;
	int			len;
	t_path		*tmp;

	sym_lnk = list_symlnk(path, opt);
	len = path_len(path) - 1;
	tmp = path;
	while (tmp)
	{
		if (tmp->type == 1)
		{
			if (sym_lnk > 0)
				ft_lprintf("\n");
			ls(tmp->name, tmp->type, opt, len);
			len += 1;
			sym_lnk = 1;
		}
		tmp = tmp->next;
	}
	return ;
}
