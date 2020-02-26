/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 00:21:39 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/28 03:37:00 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	count;
	int		len;

	count = 0;
	len = ft_strlen(dest);
	while (src[count] && count < n)
	{
		dest[count + len] = src[count];
		count++;
	}
	dest[len + count] = '\0';
	return (dest);
}
