/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgunship <lgunship@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 04:47:28 by lgunship          #+#    #+#             */
/*   Updated: 2019/09/27 21:25:30 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*header;

	if (!lst)
		return (NULL);
	header = f(lst);
	new = header;
	while (lst->next)
	{
		lst = lst->next;
		if (!(header->next = f(lst)))
		{
			free(header->next);
			return (NULL);
		}
		header = header->next;
	}
	return (new);
}
