/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#             */
/*   Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr       */
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
