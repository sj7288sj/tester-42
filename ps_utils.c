/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:23:03 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/17 12:51:21 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

long	ft_atol_ps(const char *str, size_t init, size_t last)
{
	int		sign;
	long	result;
	size_t	idx;
	size_t	len;

	sign = 1;
	result = 0;
	idx = 0;
	len = last - init;
	if (str[init + idx] == '-' || str[init + idx] == '+')
	{
		if (str[init + idx] == '-')
			sign = -1;
		idx++;
	}
	while (idx < len && ('0' <= str[init + idx] && str[init + idx] <= '9'))
	{
		result *= 10;
		result += (str[init + idx] - '0') * sign;
		if (result < -2147483648 || 2147483647 < result)
			return (result);
		idx++;
	}
	return (result);
}

t_stack	*copy_stack(t_stack *a)
{
	t_stack	*new_stack;
	t_stack	*new_node;

	new_stack = (t_stack *) malloc(sizeof(t_stack));
	if (new_stack == 0)
		return (0);
	new_stack -> data = a -> data;
	new_stack -> rank = a -> rank;
	new_node = new_stack;
	a = a -> next;
	while (a != 0)
	{
		new_node -> next = (t_stack *) malloc(sizeof(t_stack));
		if (new_node -> next == 0)
		{
			lst_free(&new_stack);
			return (0);
		}
		new_node = new_node -> next;
		new_node -> data = a -> data;
		new_node -> rank = a -> rank;
		a = a -> next;
	}
	new_node -> next = 0;
	return (new_stack);
}
