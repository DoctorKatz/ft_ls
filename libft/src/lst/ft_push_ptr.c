/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:51:11 by null              #+#    #+#             */
/*   Updated: 2020/03/10 01:42:27 by lgunship         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_push_ptr(t_mnode **head, char *ptr)
{
	t_mnode	*tmp;

	tmp = (t_mnode*)malloc(sizeof(t_mnode));
	tmp->memptr = ptr;
	tmp->next = (struct t_mnode *) (*head);
	(*head) = tmp;
}

void		ft_memlstdelete(t_mnode **head)
{
	t_mnode		*prev;
	int			i;

	prev = NULL;
	i = 0;
	while ((*head)->next)
	{
		i++;
		if ((*head)->memptr != NULL)
			free((*head)->memptr);
		prev = (*head);
		(*head) = (t_mnode *) (*head)->next;
		ft_memdel((void**)&prev);
	}
	free(*head);
}
