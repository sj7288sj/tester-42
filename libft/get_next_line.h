/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:14:25 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/16 18:57:20 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# elif BUFFER_SIZE <= 0
#  error "BUFFER_SIZE must be at least greater than '0'"
# endif

typedef struct s_lst {
	char			*content;
	size_t			len;
	size_t			idx_nl;
	size_t			idx_total;
	struct s_lst	*next;
}	t_lst;

typedef struct s_svlist {
	char			buf[BUFFER_SIZE + 1];
	int				fd;
	struct s_svlist	*next;
}	t_svlist;

char		*get_next_line(int fd);
size_t		make_node(char *buf, t_lst **lst, t_svlist **svlst, size_t len);
char		*merge_to_str(t_lst **lst, t_svlist **svlst, int fd, ssize_t r_s);
int			update_buf(t_lst *lst, t_svlist **svlist, int fd, ssize_t r_s);
t_svlist	*search_svnode(t_svlist **svlist, int fd);
void		ft_lstadd_back_gnl(t_lst **lst, t_lst *new);
void		free_mem(t_lst **lst, t_svlist **svlist, int check);
t_lst		*ft_lstnew_gnl(void *content, size_t len);
size_t		ft_strlen_gnl(const char *str);
size_t		ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);

#endif
