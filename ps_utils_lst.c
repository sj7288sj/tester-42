/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:55:05 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/19 14:00:33 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_stack	*lst_last(t_stack *node)
{
	if (node == 0)
		return (0);
	while (node -> next)
		node = node -> next;
	return (node);
}

t_stack	*lst_llast(t_stack *node)
{
	if (lst_size(node) <= 1)
		return (0);
	while (node -> next -> next)
		node = node -> next;
	return (node);
}

t_stack	*lst_new(long data, t_stack *stack)
{
	t_stack	*new;
	int		rank_below;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (new == 0)
		return (0);
	new -> data = (int) data;
	new -> rank_radix = 1;
	new -> next = 0;
	rank_below = 1;
	while (stack != 0)
	{
		if (stack -> data > new -> data)
			stack -> rank = stack -> rank + 1;
		else
			rank_below++;
		stack = stack -> next;
	}
	new -> rank = rank_below;
	return (new);
}

void	lst_free(t_stack **node)
{
	t_stack	*node_del;

	node_del = *node;
	while (node_del)
	{
		*node = (*(node))->next;
		free(node_del);
		node_del = *node;
	}
	*node = 0;
}

size_t	lst_size(t_stack *node)
{
	size_t	cnt;

	cnt = 0;
	while (node)
	{
		node = node -> next;
		cnt++;
	}
	return (cnt);
}
