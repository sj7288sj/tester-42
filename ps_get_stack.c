/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:21:51 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/19 13:03:57 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_isvalid(char *str, size_t init, size_t last, t_stack *node)
{
	long	num_atol;
	size_t	idx;
	size_t	len;

	idx = 0;
	len = last - init;
	if ((str[init + idx] == '-' || str[init + idx] == '+') && len > 1)
		idx++;
	while (idx < len)
	{
		if (str[init + idx] < '0' || '9' < str[init + idx])
			return (0);
		idx++;
	}
	num_atol = ft_atol_ps(str, init, last);
	if (num_atol < -2147483648 || 2147483647 < num_atol)
		return (0);
	while (node)
	{
		if (num_atol == node -> data)
			return (0);
		node = node -> next;
	}
	return (1);
}

static int	get_next_stack(t_stack **start, char *str, size_t len)
{
	t_stack	*new;
	ssize_t	idx;

	idx = len;
	while (idx > 0 && str[idx - 1] != ' ')
		idx--;
	if (idx != 0 || len == 0)
	{
		if (idx != 0 && get_next_stack(start, str, idx - 1) == 1)
			return (1);
		if ((size_t) idx == len)
			return (0);
	}
	if (!str || !check_isvalid(str, idx, len, *start))
		return (1);
	new = lst_new(ft_atol_ps(str, idx, len), *start);
	if (new == 0)
		return (1);
	if (*start == 0)
		*start = new;
	else
		lst_last(*start)-> next = new;
	return (0);
}

t_stack	*parse_stack(int argc, char *argv[])
{
	t_stack	*start;
	size_t	length;
	int		err_no;
	int		idx;

	start = 0;
	err_no = 0;
	idx = 0;
	while (++idx < argc)
	{
		length = ft_strlen(argv[idx]);
		err_no += get_next_stack(&start, argv[idx], length);
		if (err_no != 0)
		{
			lst_free(&start);
			return (0);
		}
	}
	return (start);
}
