/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:46:53 by null              #+#    #+#             */
/*   Updated: 2020/02/25 17:46:53 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlower(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 32 : s[i];
	return (s);
}
