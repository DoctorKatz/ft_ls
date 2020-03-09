/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 00:12:39 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/02 22:23:25 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Get the len of the file entries.
*/

int				*file_len(t_file *file)
{
	t_file		*tmp;
	int			count;
	int			*len;

	count = 0;
	len = NULL;
	if (!(len = (int*)malloc(sizeof(int) * NUM_ENTRIES)))
		return (NULL);
	tmp = file;
	while (tmp->entry[count + 1])
	{
		len[count] = 0;
		while (tmp)
		{
			if ((int)ft_strlen(tmp->entry[count]) > len[count])
				len[count] = ft_strlen(tmp->entry[count]);
			tmp = tmp->next;
		}
		tmp = file;
		count++;
	}
	len[count] = 0;
	return (len);
}
