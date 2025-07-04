/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:35:59 by mlameira          #+#    #+#             */
/*   Updated: 2024/12/08 15:56:14 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int))
{
	t_list	*dst;
	t_list	*tmp;

	dst = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&dst, del);
			return (0);
		}
		ft_lstadd_back(&dst, tmp, 0);
		lst = lst->next;
	}
	return (dst);
}
*/