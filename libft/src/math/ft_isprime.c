/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 00:07:28 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/20 00:07:31 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprime(int nb)
{
	int count;

	count = 2;
	while (count <= ft_sqrt(nb))
	{
		if ((nb % count) == 0)
			return (0);
		count++;
	}
	return (1);
}
