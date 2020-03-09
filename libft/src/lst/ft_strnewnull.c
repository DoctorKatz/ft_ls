/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewnull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 01:10:24 by lgunship          #+#    #+#             */
/*   Updated: 2020/03/10 01:12:09 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

char	*ft_strnewnull(char *newp)
{
	newp = (char*)malloc(sizeof(char) * 256);
	*newp = '\0';
	return (newp);
}
