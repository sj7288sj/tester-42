/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:02:45 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/20 15:24:39 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cnt;

	cnt = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (cnt < n)
	{
		((unsigned char *)dst)[cnt] = ((unsigned char *)src)[cnt];
		cnt++;
	}
	return (dst);
}
