/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:55:17 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/16 18:55:34 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

void	free_mem(t_lst **list, t_svlist **svlist, int check)
{
	t_lst		*node_del;
	t_svlist	*node_del2;

	if (*list != NULL || *svlist != NULL)
	{
		node_del = *list;
		node_del2 = *svlist;
		while (node_del)
		{
			*list = (*(list))-> next;
			free(node_del -> content);
			free(node_del);
			node_del = *list;
		}
		while (node_del2 && check == 1)
		{
			*svlist = (*(svlist))-> next;
			free(node_del2);
			node_del2 = *svlist;
		}
		*list = NULL;
	}
}

void	ft_lstadd_back_gnl(t_lst **lst, t_lst *new)
{
	t_lst	*node_last;
	size_t	idx_total;

	idx_total = 0;
	node_last = *lst;
	if (node_last != NULL)
	{
		while (node_last -> next)
		{
			idx_total += node_last -> len;
			node_last = node_last -> next;
		}
	}
	if (new)
	{
		if (*lst)
		{
			idx_total += node_last -> len;
			new -> idx_total = idx_total;
			node_last -> next = new;
		}
		else
			*lst = new;
	}
}

t_lst	*ft_lstnew_gnl(void	*content, size_t len)
{
	t_lst	*lst;
	size_t	cnt;

	cnt = 0;
	lst = (t_lst *) malloc(sizeof(t_lst));
	if (lst == NULL)
		return (NULL);
	lst -> len = len;
	lst -> content = (char *) malloc(lst -> len + 1);
	if (lst -> content == NULL)
	{
		free(lst);
		return (NULL);
	}
	ft_strlcpy_gnl(lst -> content, content, lst -> len + 1);
	while (cnt < lst -> len && (lst -> content)[cnt] != '\n')
		cnt++;
	lst -> idx_nl = cnt + 1;
	if (lst -> idx_nl > lst -> len)
		(lst -> idx_nl)--;
	lst -> idx_total = 0;
	lst -> next = NULL;
	return (lst);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
		cnt++;
	return (cnt);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	cnt;
	size_t	src_len;

	cnt = 0;
	src_len = ft_strlen_gnl(src);
	while (cnt < src_len && cnt + 1 < dstsize)
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	if (dstsize > 0)
		dst[cnt] = '\0';
	return (src_len);
}
