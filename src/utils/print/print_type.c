/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 00:32:51 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/10 00:32:51 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Prints the file entry type.
*/

void	print_type(t_file *file)
{
	S_ISBLK(file->stat.st_mode) ? ft_putchar('b') : 0;
	S_ISCHR(file->stat.st_mode) ? ft_putchar('c') : 0;
	S_ISDIR(file->stat.st_mode) ? ft_putchar('d') : 0;
	S_ISLNK(file->stat.st_mode) ? ft_putchar('l') : 0;
	S_ISFIFO(file->stat.st_mode) ? ft_putchar('p') : 0;
	S_ISSOCK(file->stat.st_mode) ? ft_putchar('s') : 0;
	S_ISREG(file->stat.st_mode) ? ft_putchar('-') : 0;
	return ;
}
