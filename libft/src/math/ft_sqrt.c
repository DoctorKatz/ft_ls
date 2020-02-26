/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 00:06:23 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/20 00:06:26 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int buff;
	int div;

	buff = nb;
	div = nb;
	if (nb <= 0)
		return (0);
	while (1)
	{
		div = (nb / div + div) / 2;
		if (buff > div)
			buff = div;
		else
		{
			if ((buff * buff) == nb)
				return (buff);
			else
				return (0);
		}
	}
}
