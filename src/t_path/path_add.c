/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:12:39 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/10 00:35:38 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_mnode	*g_memlst;
/*
** Checks if a path is a directory.
*/

static int		is_dir(char *path)
{
	DIR			*dir;

	if (!(dir = opendir(path)))
		return (!ft_strcmp("Not a directory", strerror(errno)) ? 0 : -1);
	return (!closedir(dir) ? 1 : -1);
}

/*
** Returns:
**   ` -1 -> A directory error
**   ` 0  -> Not a diretory
**   ` 1  -> A directory error
**   ` 2  -> A symbolic link
*/

static int		check_dir(char *path, char *opt)
{
	int			ret;
	struct stat	stt;

	ret = is_dir(path);
	if (ret > 0)
	{
		if (ft_findchr(opt, 'l') && path[ft_strlen(path) - 1] != '/')
		{
			lstat(path, &stt);
			if (S_ISLNK(stt.st_mode))
				ret = SYM_PATH;
		}
	}
	if (ret == -1)
		ft_lprintf("ls: %s: %s\n", path, strerror(errno));
	return (!ret ? SYM_PATH : ret);
}

/*
** Add a path to the path list.
*/

t_path			*path_add(t_path *path, char *dir, char *opt)
{
	t_path		*last;
	t_path		*tmp;

	if (!(last = malloc(sizeof(t_path))))
		return (NULL);
	last->type = check_dir(dir, opt);
	last->name = ft_strdup(dir);
	ft_push_ptr(&g_memlst, last->name);
	last->next = NULL;
	if (!path)
		return (last);
	tmp = path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	return (path);
}
