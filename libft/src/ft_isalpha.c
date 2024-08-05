/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:37:42 by mbonengl          #+#    #+#             */
/*   Updated: 2024/04/21 16:10:18 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		{
		printf("%d\n", ft_isalpha(argv[1][0]));
		printf("%d\n", isalpha(argv[1][0]));
	}
	return (0);
}
*/