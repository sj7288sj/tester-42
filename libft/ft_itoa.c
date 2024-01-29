/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:11:15 by seungjun          #+#    #+#             */
/*   Updated: 2023/11/15 16:25:22 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	intlen(int n)
{
	size_t	result;

	result = 0;
	if (n <= 0)
		result++;
	while (n != 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

static char	*trans_num(char *str, int n, size_t len)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign *= -1;
		str[0] = '-';
	}
	while (n)
	{
		str[--len] = (n % 10) * sign + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str_num;
	size_t	len;

	len = intlen(n);
	str_num = (char *) malloc(len + 1);
	if (str_num == NULL)
		return (NULL);
	ft_bzero(str_num, len + 1);
	if (n == 0)
		str_num[0] = '0';
	else
		str_num = trans_num(str_num, n, len);
	return (str_num);
}
