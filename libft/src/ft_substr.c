/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:55:30 by mbonengl          #+#    #+#             */
/*   Updated: 2024/04/21 15:20:00 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*alloc_zero(void)
{
	char	*ptr;

	ptr = (char *)ft_calloc(1, sizeof(char));
	if (!ptr)
		return (NULL);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > (unsigned int)s_len)
		return (alloc_zero());
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substring = (char *)ft_calloc((len + 1), sizeof(char));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}

/*
int main(void)
{
	char	*ret;

	ret = ft_substr("01234", 4294967294, 0);
	printf("%s\n", ret);
	//printf("%d", ft_strncmp(ret, "", 1));
}
*/