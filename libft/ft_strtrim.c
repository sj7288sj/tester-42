/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:22:59 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/17 19:27:33 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	init;
	size_t	last;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	init = 0;
	last = ft_strlen(s1);
	while (s1[init] && ft_strchr(set, s1[init]))
		init++;
	while (last > 0 && ft_strchr(set, s1[last - 1]))
		last--;
	if (init >= last)
		return (ft_strdup(""));
	str = (char *) malloc(last - init + 1);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, &s1[init], last - init);
	str[last - init] = '\0';
	return (str);
}
