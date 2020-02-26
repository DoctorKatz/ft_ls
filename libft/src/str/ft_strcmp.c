/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 23:01:53 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/28 04:51:43 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t count;

	count = 0;
	while (s1[count] == s2[count] && s1[count] && s2[count])
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
