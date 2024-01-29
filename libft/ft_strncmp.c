/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:17:35 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/13 14:21:30 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while ((*s1 && *s2) && cnt < n)
	{
		if ((unsigned char) *s1++ - (unsigned char) *s2++)
			return ((unsigned char) *--s1 - (unsigned char) *--s2);
		cnt++;
	}
	if (cnt == n)
		return (0);
	else
		return ((unsigned char) *s1 - (unsigned char) *s2);
}
