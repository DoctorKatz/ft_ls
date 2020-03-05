/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:18:52 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/02 22:15:42 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Get number of blocks in a file.
*/

static int		n_blocks(t_file *file)
{
	int			total;

	total = 0;
	while (file)
	{
		total += file->stat.st_blocks;
		file = file->next;
	}
	return (total);
}

/*
** Prints files in a list.
*/

void			print_list(t_file *file, char *path, char *keys, int type)
{
	t_file		*tmp;
	int			i;
	int			*len;

	i = 0;
	tmp = file;
	(type != SYM_PATH) ? ft_lprintf("total %d\n", n_blocks(file)) : 0;
	while (tmp)
	{
		print_entry(tmp, path, keys, type);
		tmp = tmp->next;
	}
	if (!(len = file_len(file)))
		return ;
	while (file)
	{
		print_type(file);
		print_perm(file, path);
		i = -1;
		while (file->entry[++i + 1])
			print_table(len[i] + 2, file->entry[i]);//TODO: %*s!!!
		ft_lprintf(" %s\n", file->entry[i]);
		file = file->next;
	}
	free(len);
}
