/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 23:59:47 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/28 06:08:46 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ptrdest;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if ((ptrdest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		ptrdest[i] = f(s[i]);
		i++;
	}
	ptrdest[i] = '\0';
	return (ptrdest);
}
