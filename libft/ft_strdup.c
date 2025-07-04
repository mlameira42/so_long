/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:20:28 by nigger            #+#    #+#             */
/*   Updated: 2024/10/31 15:13:09 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s) + 1;
	dest = (char *)malloc(size);
	if (!dest)
		return (0);
	ft_memcpy(dest, s, size);
	return (dest);
}
/*
#include <string.h>

int	main(int argc, char const *argv[])
{
	const char	*og;
	char		*dup;

	og = "alguma cena ai";
	dup = ft_strdup(og);
	if(strcmp(og, dup) == 0)
		printf("correu bem");
	else
		printf("Ocorreu um problema na %s\n", dup);
	return (0);
}
*/
