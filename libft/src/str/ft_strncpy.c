/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:39:19 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/28 04:21:42 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t count;

	count = 0;
	while (count < len && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	while (count < len)
	{
		dst[count] = '\0';
		count++;
	}
	return (dst);
}
