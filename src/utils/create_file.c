/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 00:32:51 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/10 00:32:51 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Returns a directory or a file depending on the type give as argument.
*/

t_file		*create_file(char *path, char *opt, int type)
{
	t_file		*file;

	file = (type == 1 ? file_dir(path, opt) : file_ini(path));
	file = file_srt(file, opt);
	return (file);
}
