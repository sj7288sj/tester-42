/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:51:33 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/14 17:25:49 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

static int	get_flagstr(char *dest, char flag, va_list ap)
{
	char	*flag_set;
	ssize_t	length;
	size_t	cnt;

	flag_set = "cidxXusp%";
	length = 0;
	cnt = 0;
	while (flag_set[cnt] && flag != flag_set[cnt])
		cnt++;
	if (0 <= cnt && cnt <= 5)
		length += trans_int(dest, ap, flag_set[cnt]);
	else if (cnt == 6)
		length += trans_str(dest, ap);
	else if (cnt == 7)
		length += trans_addr(dest, ap);
	else if (cnt == 8)
	{
		if (dest != 0)
			dest[0] = '%';
		length += 1;
	}
	else
		length = -1;
	return (length);
}

static int	get_printstr(char *dest, const char *src, va_list ap)
{
	ssize_t	len_flag;
	size_t	cnt_src;
	size_t	cnt_dest;

	cnt_src = 0;
	cnt_dest = 0;
	while (src[cnt_src])
	{
		if (src[cnt_src + 1] && src[cnt_src] == '%')
		{
			cnt_src++;
			len_flag = get_flagstr(&dest[cnt_dest], src[cnt_src], ap);
			if (len_flag == -1)
				return (-1);
			cnt_dest += len_flag;
		}
		else
		{
			dest[cnt_dest] = src[cnt_src];
			cnt_dest++;
		}
		cnt_src++;
	}
	dest[cnt_dest] = '\0';
	return (cnt_dest);
}

static int	get_printlen(const char *str, size_t *len, va_list ap)
{
	ssize_t	len_flag;
	size_t	cnt;

	cnt = 0;
	while (str[cnt])
	{
		if (str[cnt + 1] && str[cnt] == '%')
		{
			len_flag = get_flagstr(0, str[cnt + 1], ap);
			if (len_flag == -1)
			{
				va_end(ap);
				return (-1);
			}
			*len += len_flag;
			cnt++;
		}
		else
			(*len) = (*len) + 1;
		cnt++;
	}
	va_end(ap);
	return (*len);
}

int	ft_printf(const char *str, ...)
{
	char	*res;
	size_t	len;
	va_list	ap;

	len = 0;
	va_start(ap, str);
	if (get_printlen(str, &len, ap) < 0)
		return (-1);
	va_end(ap);
	va_start(ap, str);
	res = (char *) malloc(len + 1);
	if (res == NULL || get_printstr(res, str, ap) < 0)
	{
		va_end(ap);
		free(res);
		return (-1);
	}
	va_end(ap);
	if (write(1, res, len) < 0)
	{
		free(res);
		return (-1);
	}
	free(res);
	return (len);
}
