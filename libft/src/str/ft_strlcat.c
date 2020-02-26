/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 00:15:06 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/20 00:15:06 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*dest_cpy;
	const char		*src_cpy;
	size_t			count;
	size_t			dlen;

	count = size;
	dest_cpy = dest;
	src_cpy = src;
	while (count-- && *dest_cpy)
		dest_cpy++;
	dlen = dest_cpy - dest;
	count = size - dlen;
	if (count == 0)
		return (dlen + ft_strlen((char *)src_cpy));
	while (*src_cpy)
	{
		if (count != 1)
		{
			*dest_cpy++ = *src_cpy;
			--count;
		}
		src_cpy++;
	}
	*dest_cpy = '\0';
	return (dlen + (src_cpy - src));
}
