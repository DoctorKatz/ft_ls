/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:36:20 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/27 22:59:30 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strlen(const char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static char		*ft_strcpy(const char *dest, const char *src)
{
	int		count_src;
	char	*temp;

	count_src = 0;
	temp = (char *)dest;
	while (src[count_src])
	{
		temp[count_src] = src[count_src];
		count_src++;
	}
	temp[count_src] = '\0';
	return (temp);
}

char			*ft_strdup(char *src)
{
	char *temp = 0;

	if ((temp = (char*)malloc(ft_strlen(src) * sizeof(char) + 1)) == NULL)
		return (NULL);
	ft_strcpy(temp, src);
	return (temp);
}
