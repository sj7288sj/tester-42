/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungjun <seungjun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:13:25 by seungjun          #+#    #+#             */
/*   Updated: 2023/10/16 16:11:13 by seungjun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc_mem;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size && count > (size_t) -1 / size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	alloc_mem = malloc(count * size);
	if (alloc_mem)
		ft_bzero(alloc_mem, count * size);
	return (alloc_mem);
}
