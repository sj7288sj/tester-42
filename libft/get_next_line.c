/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:35:19 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/16 18:57:07 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

t_svlist	*search_svnode(t_svlist **svlist, int fd)
{
	t_svlist	*svnode;
	t_svlist	*new_node;

	svnode = *svlist;
	while (svnode != NULL && svnode -> next && svnode -> fd != fd)
		svnode = svnode -> next;
	if (svnode == NULL || svnode -> fd != fd)
	{
		new_node = (t_svlist *) malloc(sizeof(t_svlist));
		if (new_node == NULL)
			return (NULL);
		(new_node -> buf)[0] = 0;
		new_node -> fd = fd;
		new_node -> next = NULL;
		if (svnode == NULL)
			*svlist = new_node;
	}
	if (svnode == NULL)
		return (*svlist);
	else if (svnode -> fd != fd)
	{
		svnode -> next = new_node;
		svnode = svnode -> next;
	}
	return (svnode);
}

int	update_buf(t_lst *list, t_svlist **svlist, int fd, ssize_t r_size)
{
	t_svlist	*svnode;
	t_svlist	*fd_svnode;
	ssize_t		cnt;

	svnode = *svlist;
	fd_svnode = search_svnode(svlist, fd);
	while (svnode != fd_svnode && svnode -> next != fd_svnode)
		svnode = svnode -> next;
	if (r_size < 0 || list == NULL)
	{
		if (svnode == fd_svnode)
			*svlist = (*svlist)-> next;
		else
			svnode -> next = fd_svnode -> next;
		free(fd_svnode);
		return (0);
	}
	while (list -> next)
		list = list -> next;
	cnt = -1;
	while (++cnt + list->idx_nl < list->len)
		(fd_svnode->buf)[cnt] = (list -> content)[cnt + list -> idx_nl];
	while (cnt < BUFFER_SIZE)
		(fd_svnode->buf)[cnt++] = 0;
	return (1);
}

char	*merge_to_str(t_lst **list, t_svlist **svlist, int fd, ssize_t r_size)
{
	t_lst	*node;
	char	*str;

	if (*svlist == NULL || update_buf(*list, svlist, fd, r_size) == 0)
	{
		free_mem(list, svlist, 0);
		return (NULL);
	}
	node = *list;
	while (node -> next)
		node = node -> next;
	str = (char *) malloc(node -> idx_total + node -> idx_nl + 1);
	if (str == NULL)
		free_mem(list, svlist, 1);
	node = *list;
	while (node)
	{
		ft_strlcpy_gnl(&str[node->idx_total], node->content, node->idx_nl + 1);
		node = node -> next;
	}
	free_mem(list, svlist, 0);
	return (str);
}

size_t	make_node(char *buf, t_lst **list, t_svlist **svlist, size_t len)
{
	t_lst	*node_new;

	buf[len] = 0;
	node_new = ft_lstnew_gnl(buf, len);
	if (node_new == NULL)
	{
		free_mem(list, svlist, 1);
		return (1);
	}
	ft_lstadd_back_gnl(list, node_new);
	if ((node_new -> content)[node_new -> len - 1] == '\n')
		return (1);
	return ((node_new->len) - (node_new->idx_nl));
}

char	*get_next_line(int fd)
{
	static t_svlist	*svlist;
	t_svlist		*svnode;
	ssize_t			r_size;
	t_lst			*list;
	char			*buf;

	list = NULL;
	svnode = search_svnode(&svlist, fd);
	if (svnode == NULL)
		return (NULL);
	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
	{
		free_mem(&list, &svlist, 1);
		return (NULL);
	}
	r_size = ft_strlen_gnl(svnode -> buf);
	if (r_size == 0 || make_node(svnode->buf, &list, &svlist, r_size) == 0)
	{
		r_size = read(fd, buf, BUFFER_SIZE);
		while (r_size > 0 && make_node(buf, &list, &svlist, r_size) == 0)
			r_size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (merge_to_str(&list, &svlist, fd, r_size));
}
