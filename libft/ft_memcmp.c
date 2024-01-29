/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:57:39 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/13 14:28:27 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n)
	{
		if (((unsigned char *)s1)[cnt] - ((unsigned char *)s2)[cnt])
			return (((unsigned char *)s1)[cnt] - ((unsigned char *)s2)[cnt]);
		cnt++;
	}
	return (0);
}
