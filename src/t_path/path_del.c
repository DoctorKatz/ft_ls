/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:12:39 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/02 22:23:25 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Delete a path from the path list.
*/

void		path_del(t_path *path)
{
	t_path	*tmp;

	while (path)
	{
		if (path->type == DIR_ERR)
		{
			ft_strdel(&(path->name));
			path->name = NULL;
		}
		tmp = path;
		path = path->next;
		free(tmp);
	}
	return ;
}
