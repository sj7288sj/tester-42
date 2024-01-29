/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:37:03 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/17 12:40:36 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static void	algo_size_3(t_stack **a, t_stack **b, int size)
{
	int	n1;
	int	n2;

	n1 = (*a)-> rank;
	n2 = (*a)-> next -> rank;
	if (size == 4 || size == 5)
	{
		n1 = n1 - size + 3;
		n2 = n2 - size + 3;
	}
	if ((n1 == 1 && n2 == 3) || (n1 == 2 && n2 == 1) || (n1 == 3 && n2 == 2))
		swap('a', a, b, 1);
	if ((n1 == 1 && n2 == 3) || (n1 == 3 && n2 == 1))
		rotate('a', a, b, 1);
	if ((n1 == 2 && n2 == 3) || (n1 == 3 && n2 == 2))
		revrot('a', a, b, 1);
}

static void	algo_size_4(t_stack **a, t_stack **b)
{
	while ((*a)-> rank != 1)
		rotate('a', a, b, 1);
	push('b', a, b, 1);
	algo_size_3(a, b, 4);
	push('a', a, b, 1);
}

static void	algo_size_5(t_stack **a, t_stack **b)
{
	int	pos_rank2;
	int	idx;

	pos_rank2 = 0;
	idx = 0;
	while ((*a)-> rank != 1)
	{
		if ((*a)-> rank == 2)
			pos_rank2 = idx;
		rotate('a', a, b, 1);
		idx++;
	}
	push('b', a, b, 1);
	while ((*a)-> rank != 2)
	{
		if (pos_rank2 == 3)
			revrot('a', a, b, 1);
		else
			rotate('a', a, b, 1);
	}
	push('b', a, b, 1);
	algo_size_3(a, b, 5);
	push('a', a, b, 1);
	push('a', a, b, 1);
}

void	algo_main(t_stack **a)
{
	t_stack	*b;
	size_t	size_a;

	b = 0;
	size_a = lst_size(*a);
	if (size_a == 1 || (size_a == 2 && (*a)-> rank == 1))
		return ;
	else if (size_a == 2 && (*a)-> rank == 2)
		swap('a', a, &b, 1);
	else if (size_a == 3)
		algo_size_3(a, &b, 3);
	else if (size_a == 4)
		algo_size_4(a, &b);
	else if (size_a == 5)
		algo_size_5(a, &b);
	else
	{
		if (algo_radix(a, &b, size_a) == 0)
		{
			write(2, "Error\n", 6);
			return ;
		}
		while (b != 0)
			push('a', a, &b, 1);
	}
}
