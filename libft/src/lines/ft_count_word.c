/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 03:22:41 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/21 03:22:41 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_word(const char *str, char c)
{
	int words_quantity;

	if (!str)
		return (0);
	words_quantity = 0;
	while (str)
	{
		if (*str == c && *str != c)
			words_quantity++;
		str++;
	}
	return (words_quantity);
}
