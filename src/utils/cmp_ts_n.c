/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_ts_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 00:32:51 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/10 00:32:51 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Compare timestap vs name.
** Returns :
**   - If time is equal, return the difference between the names.
**   - If time is different, return the difference between the times.
*/

int			cmp_ts_n(int a, int b, char *s1, char *s2)
{
	return (a == b ? ft_strcmp(s1, s2) : a - b);
}
