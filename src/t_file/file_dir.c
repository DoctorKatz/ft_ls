/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:12:39 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/10 00:44:00 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Create a file directory.
*/

static t_file		*file_dir_create(DIR *ptr, char *path, char *opt)
{
	t_file			*dir;
	struct dirent	*ret;
	char			*cpath;
	struct stat		vstat;

	dir = NULL;
	while ((ret = readdir(ptr)))
	{
		if (ret->d_name[0] == '.' && !ft_findchr(opt, 'f') \
				&& !ft_findchr(opt, 'a') && !ft_findchr(opt, 'A'))
			continue;
		if ((!ft_strcmp(".", ret->d_name) || !ft_strcmp("..", ret->d_name)) \
				&& ft_findchr(opt, 'A'))
			continue;
		cpath = ft_zlprintf("%s/%s", path, ret->d_name);
		lstat(cpath, &vstat);
		dir = file_add(dir, ret->d_name, vstat, ret->d_type);
	}
	if (ret)
		free(ret);
	return (dir);
}

/*
** Returns a file directory entry if the path is a directory.
*/

t_file				*file_dir(char *path, char *opt)
{
	t_file			*dir;
	DIR				*ptr;

	dir = NULL;
	ptr = opendir(path);
	if (ptr)
	{
		dir = file_dir_create(ptr, path, opt);
		closedir(ptr);
	}
	else
		ft_lprintf("ls: %s: %s\n", path, strerror(errno));
	return (dir);
}
