/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:38:11 by nigger            #+#    #+#             */
/*   Updated: 2024/11/05 02:36:49 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!d && !s)
		return (0);
	if (dest > src)
		while (n-- != 0)
			d[n] = s[n];
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*
#include <string.h>

int	main(int argc, char const *argv[])
{
	char dest[20];
	char src2[20] = "Hello, World";
	char src[20] = "Hello, World";
	printf("Resultado do ft: %s\nResultado do memcpy: %s\n",
		(unsigned char *)ft_memmove(src + 2, src, 12),
		(unsigned char *)memmove(src2 + 2,src2,12));
		printf("Resultado do dest ft: %s\nResultado do dest memcpy: %s\n", src,
			src2);

	return (0);
}*/
