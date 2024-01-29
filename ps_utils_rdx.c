/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_rdx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:01:39 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/17 13:18:57 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	trans_to_rdx(int num, int digit, int num_divide)
{
	if (num_divide == 3)
	{	
		while (--digit > 0)
			num /= num_divide;
		return (num % num_divide);
	}
	else
	{
		if (1 <= num && num <= 26)
			return (0);
		else if (27 <= num && num <= 53)
			return (1);
		else if (54 <= num && num <= 80)
			return (2);
		else
			return (3);
	}
}

int	get_3rdx_maxdigit(t_stack *node)
{
	int		max_td;
	int		max_data;
	t_stack	*node_max;

	max_td = 0;
	node_max = 0;
	while (node != 0)
	{
		if (node_max == 0)
			node_max = node;
		else if (node_max -> rank < node -> rank)
			node_max = node;
		node = node -> next;
	}
	max_data = node_max -> data;
	while (max_data > 0)
	{
		max_data = max_data / 3;
		max_td++;
	}
	return (max_td);
}

void	get_rankrdx(t_stack *a, t_stack **a_cp, t_stack **b)
{
	t_stack	*search_node;
	int		rank_idx;

	while (*b != 0)
		push('a', a_cp, b, 0);
	while (a != 0)
	{
		rank_idx = a -> rank - 1;
		search_node = *a_cp;
		while (rank_idx != 0)
		{
			search_node = search_node -> next;
			rank_idx--;
		}
		a -> rank_radix = search_node -> rank;
		a = a -> next;
	}
}
