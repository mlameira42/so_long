/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:10:46 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/13 10:39:49 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ani(t_game_args *vars, void *toget[3])
{
	int		i;
	void	*img;

	img = vars->player->img->img;
	i = 0;
	if (!img)
		return (toget[0]);
	while (i < 3 && toget[i] != img)
		i++;
	if (i >= 2)
		i = 0;
	return (toget[++i]);
}

int	movehandle(int key, t_game_args *vars, int dest)
{
	char	*num;

	if (key == 'd' && ismove_allowed(vars, dest, "RIGHT", '1'))
		vars->player->img->img = ani(vars, vars->player->walk.right);
	else if (key == 'a' && ismove_allowed(vars, dest, "LEFT", '1'))
		vars->player->img->img = ani(vars, vars->player->walk.left);
	else if (key == 'w' && ismove_allowed(vars, dest, "UP", '1'))
		vars->player->img->img = ani(vars, vars->player->walk.up);
	else if (key == 's' && ismove_allowed(vars, dest, "DOWN", '1'))
		vars->player->img->img = ani(vars, vars->player->walk.down);
	else
		return (1);
	if (key == 'w' || key == 's')
		vars->player->img->y = dest;
	else if (key == 'a' || key == 'd')
		vars->player->img->x = dest;
	vars->player->moviment++;
	num = ft_itoa(vars->player->moviment);
	ft_putstr_fd(num, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	free(num);
	map_gen(vars);
	keyhit(vars, key);
	return (0);
}

int	loadimg(t_game_args *vars)
{
	vars->img->img = mlx_xpm_file_to_image(vars->init, "./textures/back.xpm", \
	&vars->img->width, &vars->img->heigh);
	vars->img->wall->img = mlx_xpm_file_to_image(vars->init, \
	"./textures/wall.xpm", &vars->img->wall->width, &vars->img->wall->heigh);
	vars->img->dc.coin = mlx_xpm_file_to_image(vars->init, \
	"./textures/key.xpm", &vars->img->dc.coinw, &vars->img->dc.coinh);
	vars->img->dc.door = mlx_xpm_file_to_image(vars->init, \
	"./textures/door_opened.xpm", &vars->img->dc.dwidth, &vars->img->dc.dheigh);
	vars->img->dc.door_closed = mlx_xpm_file_to_image(vars->init, \
	"./textures/door_closed.xpm", &vars->img->dc.dwidth, &vars->img->dc.dheigh);
	if (!vars->img->img || !vars->img->wall->img || !vars->img->dc.coin \
		|| !vars->img->dc.door || !vars->img->dc.door_closed)
		return (1);
	vars->img->x = 0;
	vars->img->y = 0;
	return (0);
}

int	game_ticks(t_game_args *vars)
{
	unsigned long	wait;
	char			*num;

	num = ft_itoa(vars->player->moviment);
	wait = 0;
	while (wait < 83333333)
		++wait;
	mlx_string_put(vars->init, vars->win, 10, 10, 0xFFFFFF, num);
	free(num);
	keyhit(vars, 'w');
	if (!vars->win)
		return (0);
	return (1);
}
