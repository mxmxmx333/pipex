/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:28:36 by mbonengl          #+#    #+#             */
/*   Updated: 2024/04/19 17:29:30 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n)
	{
		n--;
		ptr[n] = 0;
	}
}
/*Edge case !s cant be handled, because system 
ones doesnt protect for NULL Pointer *//*
int	main(void)
{
	char array[] = "Hello World!";
	char array2[] = "Hello World!";

	printf("Before bzero:%s\n", array);
	ft_bzero(array, sizeof(array));
	printf("After bzero:%s\n", array);
	printf("------- System bzero:-------\n");
	printf("Before bzero:%s\n", array2);
	bzero(array2, sizeof(array));
	printf("After bzero:%s\n", array2);
	return (0);
}
*/