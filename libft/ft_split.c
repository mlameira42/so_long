/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:48:46 by nigger            #+#    #+#             */
/*   Updated: 2025/03/03 09:45:50 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_instances(const char *s, char c)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	inst;
	size_t	substr_begin;

	inst = 0;
	dest = (char **)ft_calloc(ft_instances(s, c) + 1, sizeof(char *));
	if (!dest)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			substr_begin = 0;
			while (*s && *s != c && ++substr_begin)
				++s;
			dest[inst++] = ft_substr(s - substr_begin, 0, substr_begin);
		}
		else
			++s;
	}
	dest[inst] = NULL;
	return (dest);
}
