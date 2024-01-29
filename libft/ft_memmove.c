/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:51:05 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/11 19:49:19 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	cnt;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		cnt = 0;
		while (cnt < len)
		{
			((unsigned char *)dst)[cnt] = ((unsigned char *)src)[cnt];
			cnt++;
		}
	}
	else
	{
		cnt = len;
		while (cnt > 0)
		{
			((unsigned char *)dst)[cnt - 1] = ((unsigned char *)src)[cnt - 1];
			cnt--;
		}
	}
	return (dst);
}
