/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyamount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:19:01 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/13 10:46:07 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	item_amount(char **map, char tofind)
{
	int	i;
	int	j;
	int	amount;

	amount = 0;
	i = -1;
	if (!map)
		return (-1);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == tofind)
				amount++;
	}
	return (amount);
}

int	destroy(t_game_args *vars)
{
	free_all(vars);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ismap_toobig(t_game_args *vars)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = -1;
	mlx_get_screen_size(vars->init, &x, &y);
	while (vars->map[++i])
		;
	if (x < ((int)ft_strlen(vars->map[0])) * vars->img->width)
		return (1);
	else if (y < i * vars->img->heigh)
		return (1);
	return (0);
}
