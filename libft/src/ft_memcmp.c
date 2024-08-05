/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:39:36 by mbonengl          #+#    #+#             */
/*   Updated: 2024/04/21 15:20:08 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (ptr1 != NULL && ptr2 != NULL && *ptr1 == *ptr2 && --n)
	{
		ptr1++;
		ptr2++;
	}
	return (*ptr1 - *ptr2);
}
/*
int	main(void)
{
	printf("%d",ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
	return (0);
}
*/