/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:56:39 by marvin            #+#    #+#             */
/*   Updated: 2025/02/14 15:24:41 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dec(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_dec(n);
	dest = (char *)ft_calloc(i + 1, sizeof(char));
	if (!dest)
		return ((void *)0);
	if (n == 0)
		dest[0] = '0';
	if (n < 0)
	{
		n = -n;
		dest[0] = '-';
	}
	while (n)
	{
		dest[--i] = n % 10 + '0';
		n /= 10;
	}
	return (dest);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(42));
}*/
