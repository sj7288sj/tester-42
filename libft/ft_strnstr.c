/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:45:28 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/17 17:17:23 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cnt;
	size_t	len_needle;

	cnt = 0;
	len_needle = ft_strlen(needle);
	if (len_needle == 0)
		return ((char *) haystack);
	while (*haystack && cnt < len)
	{
		if (cnt + len_needle > len)
			return (NULL);
		else if (ft_strncmp(haystack++, needle, len_needle) == 0)
			return ((char *)--haystack);
		cnt++;
	}
	return (NULL);
}
