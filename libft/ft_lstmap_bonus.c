/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:40:44 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/18 13:46:25 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*node_new;
	void	*temp;

	if (!lst)
		return (NULL);
	lst_new = NULL;
	while (lst)
	{
		temp = f(lst -> content);
		node_new = ft_lstnew(temp);
		if (node_new == NULL)
		{
			ft_lstclear(&lst_new, del);
			del(temp);
			return (NULL);
		}
		ft_lstadd_back(&lst_new, node_new);
		lst = lst -> next;
	}
	return (lst_new);
}
