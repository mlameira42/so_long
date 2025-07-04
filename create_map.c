/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:14:56 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/03 10:48:41 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	putimg(t_game_args *vars, int posx, int posy)
{
	if (vars->map[posy][posx] == 'C')
		mlx_put_image_to_window(vars->init, vars->win, vars->img->dc.coin, \
		posx * vars->img->width, posy * vars->img->heigh);
	else if (vars->map[posy][posx] == 'E')
	{
		if (item_amount(vars->map, 'C') != 0)
			mlx_put_image_to_window(vars->init, vars->win, \
			vars->img->dc.door_closed, posx * vars->img->width, posy \
			* vars->img->heigh);
		else
			mlx_put_image_to_window(vars->init, vars->win, vars->img->dc.door, \
					posx * vars->img->width, posy * vars->img->heigh);
	}
}

int	map_gen(t_game_args *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] != '1')
			{
				mlx_put_image_to_window(vars->init, vars->win, vars->img->img, \
				j * vars->img->width, i * vars->img->heigh);
				putimg(vars, j, i);
			}
			else
				mlx_put_image_to_window(vars->init, vars->win, \
						vars->img->wall->img, j * vars->img->wall->width, i \
						* vars->img->wall->width);
		}
	}
	mlx_put_image_to_window(vars->init, vars->win, vars->player->img->img, \
			vars->player->img->x, vars->player->img->y);
	return (0);
}
