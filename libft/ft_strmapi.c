/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:52:09 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/18 14:06:21 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	cnt;
	size_t			len_s;
	char			*s_mapi;

	cnt = 0;
	len_s = ft_strlen(s);
	s_mapi = (char *) malloc(len_s + 1);
	if (s_mapi == NULL)
		return (NULL);
	while (s[cnt])
	{
		s_mapi[cnt] = f(cnt, s[cnt]);
		cnt++;
	}
	s_mapi[cnt] = '\0';
	return (s_mapi);
}
