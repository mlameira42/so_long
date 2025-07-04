/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:34:51 by mlameira          #+#    #+#             */
/*   Updated: 2024/11/05 02:34:52 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		++s;
		--n;
	}
	return ((void *)0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char const *argv[])
{
	printf("Resultado do ft: %p\nResultado do memchr: %p\n",
		ft_memchr("Convicdado",'c',6), memchr("Convicdado", 'c',6));
	return (0);
}
*/
