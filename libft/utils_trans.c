/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trans.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:47:41 by seungjun          #+#    #+#             */
/*   Updated: 2023/11/17 15:54:02 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#include "ft_printf.h"

static char	*trans_num(char *str, size_t n, size_t len, char flag)
{
	char	*hexanum;
	int		sign;
	int		binary;

	hexanum = "0123456789abcdef";
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		str[0] = '-';
	}
	binary = 10;
	if (flag == 'x' || flag == 'X')
		binary = 16;
	while (n)
	{
		if (flag == 'x' || flag == 'X')
			str[--len] = hexanum[(n % 16) * sign];
		if (flag == 'X')
			str[len] = ft_toupper(str[len]);
		if (flag == 'u')
			str[--len] = (n % 10) * sign + '0';
		n /= binary;
	}
	return (str);
}

static char	*ft_itoa_base(size_t num, char flag)
{
	char	*res_str;
	size_t	num_cp;
	size_t	len;

	num_cp = num;
	len = 0;
	if (num_cp <= 0)
		len++;
	while (num_cp != 0)
	{
		if (flag == 'x' || flag == 'X')
			num_cp /= 16;
		else
			num_cp /= 10;
		len++;
	}
	res_str = (char *) malloc(len + 1);
	if (res_str == 0)
		return (0);
	ft_bzero(res_str, len + 1);
	if (num == 0)
		res_str[0] = '0';
	res_str = trans_num(res_str, num, len, flag);
	return (res_str);
}

ssize_t	trans_addr(char *dest, va_list ap)
{
	char	*res_str;
	size_t	len_str;
	size_t	addr_va;

	addr_va = va_arg(ap, size_t);
	res_str = ft_itoa_base(addr_va, 'x');
	if (res_str == 0)
		return (-1);
	len_str = ft_strlen(res_str);
	if (dest != 0)
	{
		ft_strlcpy(dest, "0x", 3);
		ft_strlcpy(&(dest[2]), res_str, len_str + 1);
	}
	free(res_str);
	return (len_str + 2);
}

ssize_t	trans_str(char *dest, va_list ap)
{
	size_t	len_str;
	char	*res_str;

	res_str = va_arg(ap, char *);
	if (res_str == 0)
	{
		if (dest != 0)
			ft_strlcpy(dest, "(null)", 7);
		return (6);
	}
	len_str = ft_strlen(res_str);
	if (dest != 0)
		ft_strlcpy(dest, res_str, len_str + 1);
	return (len_str);
}

ssize_t	trans_int(char *dest, va_list ap, char flag)
{
	ssize_t	res_int;
	size_t	len_str;
	char	*res_str;

	if (flag == 'u' || flag == 'x' || flag == 'X')
		res_int = va_arg(ap, unsigned int);
	else
		res_int = va_arg(ap, int);
	if (flag == 'c')
	{
		if (dest != 0)
			dest[0] = res_int;
		return (1);
	}
	if (flag == 'd' || flag == 'i')
		res_str = ft_itoa(res_int);
	else
		res_str = ft_itoa_base(res_int, flag);
	if (res_str == 0)
		return (-1);
	len_str = ft_strlen(res_str);
	if (dest != 0)
		ft_strlcpy(dest, res_str, len_str + 1);
	free(res_str);
	return (len_str);
}
