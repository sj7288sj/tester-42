/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:30:00 by seungjun          #+#    #+#             */
/*   Updated: 2023/11/06 16:52:20 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length_dst;
	size_t	length_src;
	size_t	cnt;

	cnt = 0;
	length_dst = ft_strlen(dst);
	length_src = ft_strlen(src);
	if (dstsize <= length_dst)
		return (length_src + dstsize);
	else
	{
		while (cnt < length_src && cnt + length_dst + 1 < dstsize)
		{
			dst[length_dst + cnt] = src[cnt];
			cnt++;
		}
		dst[length_dst + cnt] = '\0';
		return (length_src + length_dst);
	}
}
