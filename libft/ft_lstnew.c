/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:36:10 by mlameira          #+#    #+#             */
/*   Updated: 2024/12/08 15:59:14 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(int content, int index)
{
	t_list	*dest;

	dest = malloc(sizeof(t_list));
	if (!dest)
		return (0);
	dest->content = content;
	dest->index = index;
	dest->next = (void *)0;
	return (dest);
}
