/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line..h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:54:11 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/01 02:04:22 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_GET_NEXT_LINE_H
# define GNL_GET_NEXT_LINE_H

# define BUFF_SIZE	64

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>

int		check_line(const int fd, char **line, char **str, ssize_t read_bytes);
int		get_next_line(const int fd, char **line);

#endif
