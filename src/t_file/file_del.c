/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:12:39 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/02 22:23:25 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

extern t_mnode	*g_memlst;

/*
** Delete an entry from the file list.
*/

t_file			*file_del(t_file *file)
{
	int		i;
	t_file	*tmp;

	i = -1;
	tmp = (!file ? NULL : file->next);
	if (file || file->next)
	{
		while (file->entry[++i])
		{
			file->entry[i] = NULL;
		}
	}
	return (tmp);
}
