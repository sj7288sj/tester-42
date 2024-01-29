/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:48:53 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/19 12:55:27 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

static int	check_stack(t_stack *a)
{
	int	idx_rank;

	idx_rank = 1;
	while (a != 0)
	{
		if (a -> rank != idx_rank++)
			return (0);
		a = a -> next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;

	if (argc < 2)
		return (0);
	a = parse_stack(argc, argv);
	if (a == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_stack(a) != 1)
		algo_main(&a);
	lst_free(&a);
	return (0);
}
