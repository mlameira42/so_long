/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:27:40 by nigger            #+#    #+#             */
/*   Updated: 2024/11/05 02:36:39 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*str2;

	str = ((unsigned char *)s1);
	str2 = ((unsigned char *)s2);
	i = 0;
	while (i < n)
	{
		if (str[i] != str2[i])
			return (str[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char const *argv[])
{
	printf("Resultado do ft: %d\nResultado do memcpy: %d\n",
		ft_memcmp("Convi dado","Convidado",6),
		memcmp("Convi dado","Convidado",6));
	return (0);
}
*/
