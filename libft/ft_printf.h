/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:52:19 by seungjun          #+#    #+#             */
/*   Updated: 2024/01/14 17:23:24 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
ssize_t	trans_int(char *dest, va_list ap, char flag);
ssize_t	trans_str(char *dest, va_list ap);
ssize_t	trans_addr(char *dest, va_list ap);

#endif
