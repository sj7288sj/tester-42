/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:49:31 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/19 13:05:01 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h>

typedef struct s_stack {
	int				data;
	int				rank;
	int				rank_radix;
	struct s_stack	*next;
}	t_stack;

t_stack	*parse_stack(int argc, char *argv[]);
void	swap(char stack, t_stack **a, t_stack **b, int flag);
void	push(char stack, t_stack **a, t_stack **b, int flag);
void	rotate(char stack, t_stack **a, t_stack **b, int flag);
void	revrot(char stack, t_stack **a, t_stack **b, int flag);
void	algo_main(t_stack **a);
int		algo_radix(t_stack **a, t_stack **b, size_t size_a);
void	get_radix_data(t_stack *a, t_stack *a_cp, t_stack **b);
int		get_3rdx_maxdigit(t_stack *node);
void	get_rankrdx(t_stack *a, t_stack **a_cp, t_stack **b);
long	ft_atol_ps(const char *str, size_t init, size_t last);
t_stack	*copy_stack(t_stack *a);
t_stack	*lst_llast(t_stack *node);
t_stack	*lst_last(t_stack *node);
t_stack	*lst_new(long data, t_stack *stack);
void	lst_free(t_stack **node);
size_t	lst_size(t_stack *node);
int		trans_to_rdx(int num, int digit, int num_divide);

#endif
