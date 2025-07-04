/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:35:15 by mlameira          #+#    #+#             */
/*   Updated: 2024/11/05 02:35:18 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && '9' >= nptr[i])
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * neg);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char const *argv[])
{
	printf("My atoi: %d\nOg atoi: %d", ft_atoi("  	-50"), atoi("  	-50"));
	return (0);
}
*/
