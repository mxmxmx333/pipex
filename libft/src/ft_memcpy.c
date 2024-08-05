/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:33:38 by mbonengl          #+#    #+#             */
/*   Updated: 2024/04/21 15:20:10 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(int argc, char **argv)
{
	char src[] = "HELLO";
	char dest1[] = "holla";
	char dest2[] = "holla";
	printf("ft_memcpy: %s\n", ft_memcpy(0, 0, 1));
	//printf("memcpy:    %s\n", memcpy(0, 0, 1));
}
*/