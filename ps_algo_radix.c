/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:06:38 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/17 13:19:14 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo_3radix(t_stack **a, t_stack **b, int digit, int max_digit)
{
	int		check_cycle;
	t_stack	*node;

	check_cycle = 0;
	while ((*a != 0 && digit % 2 == 1) || (*b != 0 && digit % 2 == 0))
	{
		node = *a;
		if (digit % 2 == 0)
			node = *b;
		if (trans_to_rdx(node -> rank_radix, digit, 3) <= 1)
			push('a' + digit % 2, a, b, 1);
		if (trans_to_rdx(node -> rank_radix, digit, 3) == 1)
			rotate('a' + digit % 2, a, b, 1);
		else if (trans_to_rdx(node -> rank_radix, digit, 3) == 2)
		{
			while ((check_cycle == node -> rank_radix) && (*a != 0 && *b != 0))
				push('a' + digit % 2, a, b, 1);
			if (check_cycle == 0)
				check_cycle = node -> rank_radix;
			rotate('b' - digit % 2, a, b, 1);
		}
	}
	if (digit < max_digit)
		algo_3radix(a, b, ++digit, max_digit);
}

static void	algo_3radix_cp(t_stack **a, t_stack **b, int digit, int max_digit)
{
	int		check_cycle;
	t_stack	*node;

	check_cycle = 0;
	while ((*a != 0 && digit % 2 == 1) || (*b != 0 && digit % 2 == 0))
	{
		node = *a;
		if (digit % 2 == 0)
			node = *b;
		if (trans_to_rdx(node -> rank, digit, 3) <= 1)
			push('a' + digit % 2, a, b, 0);
		if (trans_to_rdx(node -> rank, digit, 3) == 1)
			rotate('a' + digit % 2, a, b, 0);
		else if (trans_to_rdx(node -> rank, digit, 3) == 2)
		{
			while ((check_cycle == node -> rank) && (*a != 0 && *b != 0))
				push('a' + digit % 2, a, b, 0);
			if (check_cycle == 0)
				check_cycle = node -> rank;
			rotate('b' - digit % 2, a, b, 0);
		}
	}
	if (digit < max_digit)
		algo_3radix_cp(a, b, ++digit, max_digit);
}

static void	algo_4radix(t_stack **a, t_stack **b, size_t size_a)
{
	t_stack	*node;

	while (size_a > 0)
	{
		node = *b;
		if (trans_to_rdx(node -> rank_radix, 4, 4) <= 1)
			push ('a', a, b, 1);
		if (trans_to_rdx(node -> rank_radix, 4, 4) == 1)
			rotate('a', a, b, 1);
		else if (trans_to_rdx(node -> rank_radix, 4, 4) >= 2)
			rotate('b', a, b, 1);
		size_a--;
	}
	while (*b != 0)
	{
		node = *b;
		push('a', a, b, 1);
		if (trans_to_rdx(node -> rank_radix, 4, 4) == 3)
			rotate('a', a, b, 1);
	}
}

static void	algo_4radix_cp(t_stack **a, t_stack **b, size_t size_a)
{
	t_stack	*node;

	while (size_a > 0)
	{
		node = *b;
		if (trans_to_rdx(node -> rank, 4, 4) <= 1)
			push ('a', a, b, 0);
		if (trans_to_rdx(node -> rank, 4, 4) == 1)
			rotate('a', a, b, 0);
		else if (trans_to_rdx(node -> rank, 4, 4) >= 2)
			rotate('b', a, b, 0);
		size_a--;
	}
	while (*b != 0)
	{
		node = *b;
		push('a', a, b, 0);
		if (trans_to_rdx(node -> rank, 4, 4) == 3)
			rotate('a', a, b, 0);
	}
}

int	algo_radix(t_stack **a, t_stack **b, size_t size_a)
{
	t_stack	*a_cp;
	int		max_digit;

	a_cp = copy_stack(*a);
	if (a_cp == 0)
		return (0);
	max_digit = get_3rdx_maxdigit(*a);
	if (80 < size_a && size_a < 108)
	{
		algo_3radix_cp(&a_cp, b, 1, 3);
		algo_4radix_cp(&a_cp, b, size_a);
	}
	else
		algo_3radix_cp(&a_cp, b, 1, max_digit);
	get_rankrdx(*a, &a_cp, b);
	lst_free(&a_cp);
	if (80 < size_a && size_a < 108)
	{
		algo_3radix(a, b, 1, 3);
		algo_4radix(a, b, size_a);
	}
	else
		algo_3radix(a, b, 1, max_digit);
	return (1);
}
