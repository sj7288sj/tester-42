/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:30:02 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/21 14:22:40 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
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

static void	trans_num(char *str, int n, size_t len)
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
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	char	str_num[12];

	ft_bzero(str_num, 12);
	len = intlen(n);
	if (n == 0)
		str_num[0] = '0';
	else
		trans_num(str_num, n, len);
	ft_putstr_fd(str_num, fd);
}
