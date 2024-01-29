/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:22:09 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/17 19:29:10 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len_substr;
	char	*substr;

	len_s = ft_strlen(s);
	if (len_s == 0 || start > len_s)
		return (ft_strdup(""));
	len_substr = len;
	if (len_substr > len_s - start)
		len_substr = len_s - start;
	substr = (char *) malloc(len_substr + 1);
	if (!substr)
		return (NULL);
	substr = ft_memcpy(substr, &s[start], len_substr);
	substr[len_substr] = '\0';
	return (substr);
}
