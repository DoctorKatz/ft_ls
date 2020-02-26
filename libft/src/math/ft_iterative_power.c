/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 00:09:14 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/20 00:09:15 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int count;
	int temp;

	if (power <= 0)
	{
		return (0);
	}
	temp = nb;
	count = 1;
	while (count <= power - 1)
	{
		temp = nb * temp;
		count++;
	}
	return (temp);
}
