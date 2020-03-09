/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:12:39 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/02 22:23:25 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Get the len of the path list.
*/

int		path_len(t_path *path)
{
	int len;

	len = 0;
	while (path)
	{
		path = path->next;
		len += 1;
	}
	return (len);
}
