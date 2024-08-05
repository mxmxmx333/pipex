/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:09:20 by mbonengl          #+#    #+#             */
/*   Updated: 2024/04/21 15:20:14 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n)
	{
		n--;
		ptr[n] = c;
	}
	return (ptr);
}
/*
int main(void)
{
    int arr[10];
    int arr2[10];
	int k = 0;

	printf("\n");
	k = 0;
    ft_memset(arr, 0, sizeof(int)*10);
    memset(arr2, 0, sizeof(int)*10);
    while (k < 10)
    {
        printf("%d ", arr[k]);
		k++;
    }

    k = 0;
    printf("\n");
    while (k < 10)
    {
        printf("%d ", arr2[k]);
		        k++;

    }
}
*/