/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_srt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:12:39 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/02 22:23:25 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Get the timestap of the current path.
*/

static int		get_timestap(t_path *path, char type)
{
	int			timestap;
	struct stat	tstat;

	timestap = -1;
	lstat(path->name, &tstat);
	{
		if (type == 'a')
			timestap = tstat.st_atime;
		else if (type == 'c')
			timestap = tstat.st_ctime;
		else if (type == 'm')
			timestap = tstat.st_mtime;
	}
	return (timestap);
}

/*
** Sort by time.
*/

static t_path	*sort_time(t_path *path, int reverse, char type)
{
	t_path		*begin;
	t_path		*tmp;
	int			timestap[2];

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			timestap[0] = get_timestap(path, type);
			timestap[1] = get_timestap(tmp, type);
			if ((cmp_ts_n(timestap[0], timestap[1], path->name,
						tmp->name) < 0 && !reverse) ||
					(cmp_ts_n(timestap[0], timestap[1], path->name,
						tmp->name) > 0 && reverse))
				path_swp(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}

/*
** Sort by size.
*/

static t_path	*sort_size(t_path *path, int rev)
{
	t_path		*begin;
	t_path		*tmp;
	struct stat tstat;
	struct stat pstat;

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			lstat(path->name, &pstat);
			lstat(tmp->name, &tstat);
			if ((cmp_ts_n(pstat.st_size, tstat.st_size, path->name,
						tmp->name) < 0 && !rev) ||
					(cmp_ts_n(pstat.st_size, tstat.st_size, path->name,
						tmp->name) > 0 && rev))
				path_swp(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}

/*
** Sort by name.
*/

static t_path	*sort_name(t_path *path, int rev)
{
	t_path		*begin;
	t_path		*tmp;

	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			if ((ft_strcmp(path->name, tmp->name) > 0 && !rev) ||
				(ft_strcmp(path->name, tmp->name) < 0 && rev))
				path_swp(path, tmp);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}

/*
** Sort paths correspoding to the opt flag.
** `  -r : reverse
** `  -S : size
** `  -t : time
** `    -c : last changed
** `    -u : last access
** `  -f : file
*/

t_path			*path_srt(t_path *path, char *opt)
{
	t_path		*sort;
	int			reverse;

	reverse = ft_findchr(opt, 'r');
	if (ft_findchr(opt, 'S'))
		sort = sort_size(path, reverse);
	else if (ft_findchr(opt, 't'))
	{
		if (ft_findchr(opt, 'c'))
			sort = sort_time(path, reverse, 'c');
		else if (ft_findchr(opt, 'u'))
			sort = sort_time(path, reverse, 'a');
		else
			sort = sort_time(path, reverse, 'm');
	}
	else if (ft_findchr(opt, 'f'))
		sort = path;
	else
		sort = sort_name(path, reverse);
	return (sort);
}
