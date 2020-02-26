/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 23:04:09 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/19 23:04:12 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int count;
	int sign;
	int number;

	count = 0;
	sign = 1;
	number = 0;
	if (!str[count])
		return (0);
	while ((str[count] == '\f') || (str[count] == '\n') \
			|| (str[count] == '\t') || \
			(str[count] == '\v') || (str[count] == '\r') || (str[count] == ' '))
		count++;
	if ((str[count] == '+') || (str[count] == '-'))
		if (str[count++] == '-')
			sign = -1;
	while ((str[count] >= '0') && (str[count] <= '9'))
		number = ((number * 10) + (str[count++] - '0'));
	return (number * sign);
}
