/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 00:09:40 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/13 09:46:04 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freedirs(t_dirs dir)
{
	free(dir.down);
	free(dir.left);
	free(dir.up);
	free(dir.right);
}

int	load_playerimg(t_game_args *vars, t_dirs d)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		d.down = join_tostr("./textures/walk", '0' + i, ".xpm");
		d.left = join_tostr("./textures/walk", '0' + i, "left.xpm");
		d.right = join_tostr("./textures/walk", '0' + i, "right.xpm");
		d.up = join_tostr("./textures/walk", '0' + i, "back.xpm");
		vars->player->walk.down[i] = mlx_xpm_file_to_image(vars->init, d.down,
				&vars->player->img->width, &vars->player->img->heigh);
		vars->player->walk.left[i] = mlx_xpm_file_to_image(vars->init, d.left,
				&vars->player->img->width, &vars->player->img->heigh);
		vars->player->walk.right[i] = mlx_xpm_file_to_image(vars->init, d.right,
				&vars->player->img->width, &vars->player->img->heigh);
		vars->player->walk.up[i] = mlx_xpm_file_to_image(vars->init, d.up,
				&vars->player->img->width, &vars->player->img->heigh);
		freedirs(d);
		if (!vars->player->walk.down[i] || !vars->player->walk.left[i] || \
			!vars->player->walk.right[i] || !vars->player->walk.up[i])
			return (key(65307, vars));
	}
	return (1);
}

void	keyhit(t_game_args *vars, int in)
{
	int	posx;
	int	posy;
	int	mid_point;

	mid_point = vars->player->img->width / 2;
	posx = (vars->player->img->x + mid_point) / vars->img->width;
	mid_point = vars->player->img->heigh / 2;
	posy = (vars->player->img->y + mid_point) / vars->img->heigh;
	if (in == 'w' || in == 'a' || in == 'd' || in == 's')
	{
		if (vars->map[posy][posx] == 'C')
			vars->map[posy][posx] = '0';
		else if (vars->map[posy][posx] == 'E' && !item_amount(vars->map, 'C'))
		{
			ft_putstr_fd("CONGRATS!! All keys colected!!\n", STDOUT_FILENO);
			key(65307, vars);
		}
	}
}

int	player_spwan(t_game_args *vars)
{
	int		i;
	int		j;
	t_dirs	dir;

	dir.down = 0;
	if (!load_playerimg(vars, dir))
		return (0);
	i = -1;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == 'P')
			{
				vars->player->img->x = j * vars->img->width;
				vars->player->img->y = i * vars->img->heigh;
				vars->player->img->img = vars->player->walk.down[0];
				return (1);
			}
		}
	}
	return (0);
}
