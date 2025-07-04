/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:41:02 by mlameira          #+#    #+#             */
/*   Updated: 2024/11/05 02:38:14 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	int				j;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (!little[j + 1])
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return ((void *)0);
}

/*
#include <stddef.h>
#include <stdio.h>
#include <string.h>


int	main(void)
{
	char	*dest = "Alguma coisa que nao interessa";
	char	*dest2 = "que";
	char *ptr;
	char *ptr2;

	ptr = ft_strnstr(dest, dest2, 27);
	ptr2 = strnstr(dest, dest2, 27);
	printf("Esta e a diferenca entre strnstr: %s\nE a ft_strnstr: %s\n", ptr2,
		ptr);
}*/
