/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigger <nigger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:03:39 by mlameira          #+#    #+#             */
/*   Updated: 2024/11/05 00:14:44 by nigger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (!s)
		return ((void *)0);
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	dest = (char *)ft_calloc(1, len + 1);
	if (!dest)
		return ((void *)0);
	while (i < len && start < ft_strlen(s))
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	printf("Sub string is: %s\n", ft_substr("Alguma string", 3, 13));
	return (0);
}

*/
