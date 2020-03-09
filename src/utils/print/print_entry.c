/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:12:39 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/10 00:35:38 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Relink a file entry.
*/

static char		*relink_entry(t_file *file, char *path, int type)
{
	char		buf[1024];
	char		*tmp;
	ssize_t		len;

	if (type == SYM_PATH)
		tmp = ft_strdup(path);
	else
		tmp = ft_zlprintf("%s/%s", path, file->name);
	if ((len = readlink(tmp, buf, sizeof(buf) - 1)) != -1)
		buf[len] = '\0';
	ft_strdel(&tmp);
	return (ft_zlprintf("%s -> %s", file->name, buf));
}

/*
** Prints a file entry.
*/

void			print_entry(t_file *file, char *path, char *opt, int type)
{
	int			i;

	i = 0;
	file->entry[i++] = ft_zlprintf("%d", file->stat.st_nlink);
	if (!ft_findchr(opt, 'g') && getpwuid(file->stat.st_uid))
		file->entry[i++] = ft_zlprintf("%s",
			getpwuid(file->stat.st_uid)->pw_name);
	else if (!ft_findchr(opt, 'g'))
		file->entry[i++] = ft_zlprintf("%d", file->stat.st_uid);
	file->entry[i++] = ft_zlprintf(" %s", getgrgid(file->stat.st_gid)->gr_name);
	if (S_ISCHR(file->stat.st_mode) || S_ISBLK(file->stat.st_mode))
		file->entry[i++] = ft_zlprintf("%d, %d", major(file->stat.st_rdev),
			minor(file->stat.st_rdev));
	else
		file->entry[i++] = ft_zlprintf(" %d", file->stat.st_size);
	print_date(file, opt, &i);
	if (S_ISLNK(file->stat.st_mode))
		file->entry[i++] = relink_entry(file, path, type);
	else
		file->entry[i++] = ft_zlprintf("%s", file->name);
	file->entry[i] = NULL;
	return ;
}
