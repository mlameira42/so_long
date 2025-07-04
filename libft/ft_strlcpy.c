/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:39:28 by mlameira          #+#    #+#             */
/*   Updated: 2024/11/05 02:37:55 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size <= i)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <stddef.h>
#include <stdio.h>

size_t	strlcpy(char *dest, const char *src, size_t size) {
	size_t src_len = 0;

	// Calcular o comprimento da string fonte
	while (src[src_len] != '\0') {
		src_len++;
	}

	// Se o tamanho for 0, apenas retorne o comprimento da fonte
	if (size == 0) {
		return (src_len);
	}

	// Copiar a string, garantindo que não exceda o tamanho de destino
	size_t copy_len = (src_len >= size) ? (size - 1) : src_len;

	for (size_t i = 0; i < copy_len; i++) {
		dest[i] = src[i];
	}

	// Null-terminar a string de destino
	dest[copy_len] = '\0';

	return (src_len);
}

int	main(void)
{
	char dest[6];
	char dest2[6];

	char *src = "Alguma coisa";
	printf("Resultado da string ft: %d\t strlcpy: %zu\nResultado do dest:
		%s\t dest2: %s\n", ft_strlcpy(dest, src, 6), strlcpy(dest2, src, 6),
		dest, dest2);
}*/
