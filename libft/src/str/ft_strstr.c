/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 23:00:55 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/28 05:58:14 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int count_haystack;
	int count_needle;

	count_haystack = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[count_haystack] != '\0')
	{
		count_needle = 0;
		while (needle[count_needle] == haystack[count_haystack + count_needle])
		{
			if (needle[count_needle + 1] == '\0')
				return (((char *)haystack + count_haystack));
			count_needle++;
		}
		count_haystack++;
	}
	return (NULL);
}
