/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:06:14 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/31 17:14:52 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node_del;

	node_del = *lst;
	while (node_del)
	{
		*lst = (*(lst))->next;
		ft_lstdelone(node_del, del);
		node_del = *lst;
	}
	node_del = NULL;
}
