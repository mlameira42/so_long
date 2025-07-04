/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:34:31 by mlameira          #+#    #+#             */
/*   Updated: 2024/11/05 02:37:50 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dst[i] && i < size)
		i++;
	return (ft_strlcpy(dst + i, src, size - i) + i);
}
/*

#include <stddef.h>

size_t	strlcat(char *dst, const char *src, size_t size) {
	size_t dst_len = 0;
	size_t src_len = 0;

	// Calcular o comprimento da string de destino
	while (dst[dst_len] != '\0' && dst_len < size) {
		dst_len++;
	}

	// Calcular o comprimento da string fonte
	while (src[src_len] != '\0') {
		src_len++;
	}

	// Se o comprimento de dst já é maior ou igual a size,
		não é possível concatenar
	if (dst_len >= size) {
		return (size + src_len);
	}

	// Calcular quantos caracteres podem ser copiados da fonte
	size_t copy_len = size - dst_len - 1;
		// Reservar espaço para o terminador nulo

	// Concatenar até o limite
	size_t i;
	for (i = 0; i < copy_len && src[i] != '\0'; i++) {
		dst[dst_len + i] = src[i];
	}

	// Null-terminar a string de destino
	dst[dst_len + i] = '\0';

	return (dst_len + src_len);
		// Retornar o comprimento total da string concatenada
}


#include <stdio.h>

int	main(void) {
	char dest[20] = "Hello, ";
	char dest2[20] = "Hey, ";
	const char *src = "World!";

	size_t result = strlcat(dest, src, sizeof(dest));
	int	algo = ft_strlcat(dest2, src, sizeof(dest2));
	printf("Resultado: %zu\nString concatenada: %s\nResulto2:
		%d\nString2 contatenado: %s", result, dest, algo, dest2);
		// Esperado: "Hello, World!"
}*/
