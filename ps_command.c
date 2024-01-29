/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:36:58 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/19 12:43:09 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char stack, t_stack **a, t_stack **b, int flag)
{
	t_stack	*node_first;
	t_stack	*node_second;

	if ((stack == 'a' || stack == 'b' || stack == 's') && flag == 1)
		ft_printf("s%c\n", stack);
	if (lst_size(*a) > 1 && (stack == 'a' || stack == 's'))
	{
		node_first = *a;
		node_second = (*a)-> next;
		node_first -> next = node_second -> next;
		node_second -> next = node_first;
		*a = node_second;
	}
	if (lst_size(*b) > 1 && (stack == 'b' || stack == 's'))
	{
		node_first = *b;
		node_second = (*b)-> next;
		node_first -> next = node_second -> next;
		node_second -> next = node_first;
		*b = node_second;
	}
}

void	push(char stack, t_stack **a, t_stack **b, int flag)
{
	t_stack	*node_push;

	if ((stack == 'a' || stack == 'b') && flag == 1)
		ft_printf("p%c\n", stack);
	if (stack == 'a' && *b != 0)
	{
		node_push = *b;
		*b = (*b)-> next;
		node_push -> next = *a;
		*a = node_push;
	}
	else if (stack == 'b' && *a != 0)
	{
		node_push = *a;
		*a = (*a)-> next;
		node_push -> next = *b;
		*b = node_push;
	}
}

void	rotate(char stack, t_stack **a, t_stack **b, int flag)
{
	t_stack	*node_rotate;
	t_stack	*node_last;

	if ((stack == 'a' || stack == 'b' || stack == 'r') && flag == 1)
		ft_printf("r%c\n", stack);
	if (lst_size(*a) > 1 && (stack == 'a' || stack == 'r'))
	{
		node_rotate = *a;
		*a = (*a)-> next;
		node_rotate -> next = 0;
		node_last = lst_last(*a);
		node_last -> next = node_rotate;
	}
	if (lst_size(*b) > 1 && (stack == 'b' || stack == 'r'))
	{
		node_rotate = *b;
		*b = (*b)-> next;
		node_rotate -> next = 0;
		node_last = lst_last(*b);
		node_last -> next = node_rotate;
	}
}

void	revrot(char stack, t_stack **a, t_stack **b, int flag)
{
	t_stack	*node_rotate;
	t_stack	*node_llast;

	if ((stack == 'a' || stack == 'b' || stack == 'r') && flag == 1)
		ft_printf("rr%c\n", stack);
	if (lst_size(*a) > 1 && (stack == 'a' || stack == 'r'))
	{
		node_llast = lst_llast(*a);
		node_rotate = node_llast -> next;
		node_rotate -> next = *a;
		node_llast -> next = 0;
		*a = node_rotate;
	}
	if (lst_size(*b) > 1 && (stack == 'b' || stack == 'r'))
	{
		node_llast = lst_llast(*b);
		node_rotate = node_llast -> next;
		node_rotate -> next = *b;
		node_llast -> next = 0;
		*b = node_rotate;
	}
}
