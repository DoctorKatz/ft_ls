/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:18:11 by lgunship          #+#    #+#             */
/*   Updated: 2020/02/26 21:43:12 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Print the name of the file entry.
*/

void	print_name(t_file *file)
{
	while (file)
	{
		ft_lprintf("%s\n", file->name);
		file = file->next;
	}
	return ;
}
