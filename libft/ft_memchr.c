/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:12:12 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/12 17:36:42 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n)
	{
		if (((unsigned char *) s)[cnt] == (unsigned char) c)
			return ((void *) &s[cnt]);
		cnt++;
	}
	return (NULL);
}
