/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:07:29 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/28 02:39:46 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *temp;

	temp = dst;
	if (src == dst)
		return (dst);
	while (n-- > 0)
		*(((unsigned char *)dst++)) = *(((unsigned char *)src++));
	return (temp);
}
