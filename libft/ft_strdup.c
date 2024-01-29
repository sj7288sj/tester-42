/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:37:10 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/20 15:14:16 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup_s1;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	dup_s1 = (char *) malloc(len_s1 + 1);
	if (dup_s1 == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	dup_s1 = ft_memcpy(dup_s1, s1, len_s1);
	dup_s1[len_s1] = '\0';
	return (dup_s1);
}
