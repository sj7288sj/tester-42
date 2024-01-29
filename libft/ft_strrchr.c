/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:27:11 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/20 15:27:27 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_chr;

	s_chr = NULL;
	while (*s)
	{
		if ((unsigned char) *s == (unsigned char) c)
			s_chr = (char *) s;
		s++;
	}
	if ((unsigned char) c == '\0')
		s_chr = (char *) s;
	return (s_chr);
}
