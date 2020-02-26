/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:42:19 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/19 22:49:08 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	int count_src;

	count_src = 0;
	while (*src && src[count_src])
	{
		dest[count_src] = src[count_src];
		count_src++;
	}
	dest[count_src] = '\0';
	return (dest);
}
