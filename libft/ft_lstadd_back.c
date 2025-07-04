/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:28:26 by nigger            #+#    #+#             */
/*   Updated: 2024/12/08 16:35:29 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *lst, int new)
{
	t_list	*dst;

	dst = ft_lstlast(lst);
	if (!dst)
		lst->content = new;
	else
		dst->next->content = new;
}
