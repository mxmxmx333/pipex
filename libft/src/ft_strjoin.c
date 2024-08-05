/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:09:15 by mbonengl          #+#    #+#             */
/*   Updated: 2024/04/21 15:22:10 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, char const *str2)
{
	char	*joined;
	int		totallen;

	if (!str1 || !str2)
		return (NULL);
	totallen = ft_strlen(str1) + ft_strlen(str2) + 1;
	joined = ft_calloc(totallen, sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, str1, totallen * sizeof(char));
	ft_strlcat(joined, str2, totallen * sizeof(char));
	return (joined);
}
