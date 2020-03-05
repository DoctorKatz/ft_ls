/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:51:11 by null              #+#    #+#             */
/*   Updated: 2020/03/05 22:22:39 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_push_ptr(t_mnode **head, char *ptr)
{
	t_mnode	*tmp;

	tmp = (t_mnode*)malloc(sizeof(t_mnode));
	tmp->memptr = ptr;
	tmp->next = (*head);
	(*head) = tmp;
}


int			ft_lstpop(t_mnode **head)
{
	t_mnode*	prev;
	int		val;

	prev = NULL;
	if (head == NULL)
	{
		exit(-1);
	}
	prev = (*head);
	val = prev->value;
	(*head) = (*head)->next;
	free(prev);
	return (val);
}


void		ft_memlstdelete(t_mnode **head)
{
	t_mnode* prev = NULL;

	while ((*head)->next)
	{
		if (((*head)->memptr != NULL) && (ft_strlen((*head)->memptr) != 0))
			free((*head)->memptr);
		prev = (*head);
		(*head) = (*head)->next;
		ft_memdel((void**)&prev);
	}
	free(*head);
}

