/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:24:52 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/18 21:47:11 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char *ptr;

	ptr = (unsigned char *)memptr;
	while (num-- > 0)
	{
		*(ptr++) = (unsigned char)val;
	}
	return (memptr);
}
