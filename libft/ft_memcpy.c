/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:08:06 by nigger            #+#    #+#             */
/*   Updated: 2024/11/05 02:36:44 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char const *argv[])
{
	char		dest[20];
	char		dest2[20];
	const char	src[20];

	src[20] = "Convidado";
	printf("Resultado do ft: %s\nResultado do memcpy: %s\n",
		(unsigned char *)ft_memcpy(dest,src,12),
		(unsigned char *)memcpy(dest2,src,12));
		printf("Resultado do dest ft: %s\nResultado do dest memcpy: %s\n", dest,
			dest2);
	return (0);
}
*/
