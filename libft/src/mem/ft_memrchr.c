/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 00:17:54 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/27 21:23:22 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memrchr(const void *s, int c, size_t n)
{
	s += n;
	while (n-- > 0)
	{
		if (*(int *)s == c)
			return (void *)s;
		s--;
	}
	return (NULL);
}
