/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:59:02 by mlameira          #+#    #+#             */
/*   Updated: 2024/11/05 02:28:04 by nigger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	int		arr_size;
	int		i;

	arr_size = nmemb * size;
	i = 0;
	dest = malloc(arr_size);
	if (!dest)
		return (0);
	while (i < arr_size)
		((unsigned char *)dest)[i++] = '\0';
	return (dest);
}
