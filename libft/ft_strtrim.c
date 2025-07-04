/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigger <nigger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:14:03 by nigger            #+#    #+#             */
/*   Updated: 2024/11/04 23:39:24 by nigger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*dest;

	if (!s1)
		return ((void *)0);
	i = 0;
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && i)
		i--;
	dest = ft_substr(s1, 0, i + 1);
	if (dest)
		return (dest);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	printf("New trimmed string %s\n", ft_strtrim("", "Aasg"));
	return (0);
}
*/
