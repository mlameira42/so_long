/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nigger <nigger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:08:21 by mlameira          #+#    #+#             */
/*   Updated: 2024/11/04 23:59:25 by nigger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			res = (char *)s;
		++s;
	}
	if (c == '\0')
		res = (char *)s;
	return (res);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("Strrchr: %s\nFt_strrchr: %s\n", strrchr("cartare privato", 't'),
		ft_strrchr("cartare privato", 't'));
}*/
