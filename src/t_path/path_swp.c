/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:12:39 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/02 22:23:25 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Swap entries between two path lists.
*/

void		path_swp(t_path *a, t_path *b)
{
	char	*name;
	int		type;

	name = a->name;
	type = a->type;
	a->name = b->name;
	a->type = b->type;
	b->name = name;
	b->type = type;
	return ;
}
