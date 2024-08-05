/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:12:16 by mbonengl          #+#    #+#             */
/*   Updated: 2024/04/21 15:16:40 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	comp;

	if (n == 0)
		return (NULL);
	comp = (unsigned char) c;
	src = (unsigned char *) s;
	while (*src != comp && --n)
		src++;
	if (*src == comp)
		return ((void *)src);
	return (NULL);
}

/* *s cannot be protected , should crash in that case*/