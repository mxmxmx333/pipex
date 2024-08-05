/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:15:20 by mbonengl          #+#    #+#             */
/*   Updated: 2024/04/21 15:16:15 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next != 0)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int main()
{
	t_list *test = ft_lstnew((void *)"testtest");

	ft_lstadd_front(&test, ft_lstnew("abc"));
	ft_lstadd_front(&test, ft_lstnew("123"));
	ft_lstadd_front(&test, ft_lstnew("&=="));
	printf("%d", ft_lstsize(test));
	return 0;
}
*/