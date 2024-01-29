/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:24:25 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/29 12:46:59 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

static int	check_sorted(t_stack *a, t_stack *b)
{
	int	idx_rank;

	idx_rank = 1;
	if (b != 0)
		return (0);
	while (a != 0)
	{
		if (a -> rank != idx_rank++)
			return (0);
		a = a -> next;
	}
	return (1);
}

static int	exec_command(t_stack **a, t_stack **b, char *cmd)
{
	int		len;
	char	c;

	len = ft_strlen(cmd);
	if (len == 3 && cmd[2] == '\n')
	{
		c = cmd[1];
		if (cmd[0] == 's' && (c == 'a' || c == 'b' || c == 's'))
			swap(c, a, b, 0);
		else if (cmd[0] == 'p' && (c == 'a' || c == 'b'))
			push(c, a, b, 0);
		else if (cmd[0] == 'r' && (c == 'a' || c == 'b' || c == 'r'))
			rotate(c, a, b, 0);
		else
			return (0);
	}
	else if (len == 4 && cmd[0] == 'r' && cmd[1] == 'r' && cmd[3] == '\n')
	{
		if (cmd[2] != 'a' && cmd[2] != 'b' && cmd[2] != 'r')
			return (0);
		revrot(cmd[2], a, b, 0);
	}
	else
		return (0);
	return (1);
}

static int	play_command(t_stack **a, t_stack **b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd != 0)
	{
		if (exec_command(a, b, cmd) == 0)
		{
			free(cmd);
			lst_free(a);
			lst_free(b);
			return (0);
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = parse_stack(argc, argv);
	if (a == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (play_command(&a, &b) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_sorted(a, b) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	lst_free(&a);
	lst_free(&b);
	return (0);
}
