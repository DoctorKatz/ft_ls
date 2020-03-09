/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_swp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:12:39 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/02 22:23:25 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Swap entries between two file lists.
*/

void	file_swp(t_file *a, t_file *b)
{
	struct stat		tmps;
	char			*tmpn;
	int				tmpt;

	tmpn = a->name;
	tmpt = a->type;
	tmps = a->stat;
	a->name = b->name;
	a->type = b->type;
	a->stat = b->stat;
	b->name = tmpn;
	b->type = tmpt;
	b->stat = tmps;
	return ;
}
