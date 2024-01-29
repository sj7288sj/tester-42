/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:44:03 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/25 16:58:41 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	divide_str(char const *s, char c)
{
	size_t	cnt_div;
	int		flag;

	cnt_div = 0;
	flag = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if ((unsigned char) *s == (unsigned char) c && flag == 1)
			flag = 0;
		else if ((unsigned char) *s != (unsigned char) c && flag == 0)
		{
			cnt_div++;
			flag = 1;
		}
		s++;
	}
	return (cnt_div);
}

static void	free_split(char **dest, size_t num_split)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < num_split)
		free(dest[cnt++]);
	free(dest);
}

static int	proc_split(char **dest, const char *src, size_t n_arr, size_t len)
{
	size_t	cnt;

	cnt = 0;
	dest[n_arr] = (char *) malloc(len + 1);
	if (dest[n_arr] == NULL)
	{
		free_split(dest, n_arr);
		return (0);
	}
	while (cnt < len)
	{
		dest[n_arr][cnt] = src[cnt];
		cnt++;
	}
	dest[n_arr][cnt] = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs_split;
	size_t	max_split;
	size_t	num_split;
	size_t	len;

	num_split = 0;
	max_split = divide_str(s, c);
	strs_split = (char **) malloc(sizeof(char *) * (max_split + 1));
	if (!s || strs_split == NULL)
		return (NULL);
	while (*s)
	{
		len = 0;
		while (*(s + len) && (unsigned char) *(s + len) != (unsigned char) c)
			len++;
		if (len++)
		{
			if (proc_split(strs_split, s, num_split++, --len) == 0)
				return (NULL);
		}
		s += len;
	}
	strs_split[max_split] = NULL;
	return (strs_split);
}
