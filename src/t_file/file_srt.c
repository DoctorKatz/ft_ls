/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_srt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:12:39 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/02 22:23:25 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Get the timestap of the current file.
*/

static int		get_timestap(t_file *file, char type)
{
	int			timestap;

	timestap = -1;
	if (file)
	{
		if (type == 'a')
			timestap = file->stat.st_atime;
		else if (type == 'c')
			timestap = file->stat.st_ctime;
		else if (type == 'm')
			timestap = file->stat.st_mtime;
	}
	return (timestap);
}

/*
** Sort by time.
*/

static t_file	*sort_time(t_file *file, int reverse, char type)
{
	t_file		*begin;
	t_file		*tmp;
	int			timestap[2];

	tmp = NULL;
	begin = file;
	while (file)
	{
		tmp = file->next;
		timestap[0] = get_timestap(file, type);
		timestap[1] = get_timestap(tmp, type);
		while (tmp)
		{
			if ((cmp_ts_n(timestap[0], timestap[1], \
					file->name, tmp->name) < 0 && !reverse) \
				|| (cmp_ts_n(timestap[0], timestap[1],
					file->name, tmp->name) > 0 && reverse))
				file_swp(file, tmp);
			tmp = tmp->next;
		}
		file = file->next;
	}
	return (begin);
}

/*
** Sort by size.
*/

static t_file	*sort_size(t_file *file, int rev)
{
	t_file		*begin;
	t_file		*tmp;

	tmp = NULL;
	begin = file;
	while (file)
	{
		tmp = file->next;
		while (tmp)
		{
			if ((cmp_ts_n(file->stat.st_size, tmp->stat.st_size,
						file->name, tmp->name) < 0 && !rev) ||
					(cmp_ts_n(file->stat.st_size, tmp->stat.st_size,
						file->name, tmp->name) > 0 && rev))
				file_swp(file, tmp);
			tmp = tmp->next;
		}
		file = file->next;
	}
	return (begin);
}

/*
** Sort by name.
*/

static t_file	*sort_name(t_file *file, int rev)
{
	t_file		*begin;
	t_file		*tmp;

	tmp = NULL;
	begin = file;
	while (file)
	{
		tmp = file->next;
		while (tmp)
		{
			if ((ft_strcmp(file->name, tmp->name) > 0 && !rev) ||
				(ft_strcmp(file->name, tmp->name) < 0 && rev))
				file_swp(file, tmp);
			tmp = tmp->next;
		}
		file = file->next;
	}
	return (begin);
}

/*
** Sort entries correspoding to the opt flag.
** `  -r : reverse
** `  -S : size
** `  -t : time
** `    -c : last changed
** `    -u : last access
** `  -f : file
*/

t_file			*file_srt(t_file *file, char *opt)
{
	t_file		*sort;
	int			reverse;

	reverse = ft_findchr(opt, 'r');
	if (ft_findchr(opt, 'S'))
		sort = sort_size(file, reverse);
	else if (ft_findchr(opt, 't'))
	{
		if (ft_findchr(opt, 'c'))
			sort = sort_time(file, reverse, 'c');
		else if (ft_findchr(opt, 'u'))
			sort = sort_time(file, reverse, 'a');
		else
			sort = sort_time(file, reverse, 'm');
	}
	else if (ft_findchr(opt, 'f'))
		sort = file;
	else
		sort = sort_name(file, reverse);
	return (sort);
}
