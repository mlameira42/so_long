/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:29:12 by mlameira          #+#    #+#             */
/*   Updated: 2024/11/05 02:38:10 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (i == n)
		return (0);
	while (s1[i] && s1[i] == s2[i])
	{
		if (i < n - 1)
			i++;
		else
			return (0);
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

/*
#include <stdio.h>

int	main(void)
{
	char	*dest = "alguma coisa ai";
	char	*dest2 = "alguma coisa aqui";

	printf("A diferenca e: %d", ft_strncmp(dest, dest2));
}*/
