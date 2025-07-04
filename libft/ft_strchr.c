/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:57:02 by mlameira          #+#    #+#             */
/*   Updated: 2024/11/05 02:37:25 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("Diferenca entre ft_strchr: %s\nE strchr: %s\n",ft_strchr("caracter",
			't'), strchr("caracter", 't') );
}*/
