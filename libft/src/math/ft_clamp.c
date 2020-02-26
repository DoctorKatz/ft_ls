/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 23:19:12 by lgunship          #+#    #+#             */
/*   Updated: 2019/12/27 23:20:27 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Clamps a value between two values
*/

double		ft_clamp(double i, double a, double b)
{
	if (i < a)
		i = a;
	if (i > b)
		i = b;
	return (i);
}
