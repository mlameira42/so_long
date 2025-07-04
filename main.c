/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:09:00 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/13 10:46:22 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*join_tostr(char *begin, char toadd, char *end)
{
	int		i;
	int		j;
	char	*dest;

	dest = malloc(ft_strlen(begin) + ft_strlen(end) + 2 * sizeof(char));
	i = -1;
	while (begin[++i])
		dest[i] = begin[i];
	dest[i] = toadd;
	j = -1;
	while (end[++j])
		dest[++i] = end[j];
	dest[++i] = '\0';
	return (dest);
}

int	key(int keycode, t_game_args *vars)
{
	if (keycode == 65307)
	{
		if (item_amount(vars->map, 'C'))
			ft_putstr_fd("Game manually finished!\n", STDOUT_FILENO);
		free_all(vars);
		exit(EXIT_FAILURE);
	}
	else if (keycode == 's')
		movehandle(keycode, vars, vars->player->img->y + SPEED);
	else if (keycode == 'w')
		movehandle(keycode, vars, vars->player->img->y - SPEED);
	else if (keycode == 'a')
		movehandle(keycode, vars, vars->player->img->x - SPEED);
	else if (keycode == 'd')
		movehandle(keycode, vars, vars->player->img->x + SPEED);
	return (0);
}

void	values_init(t_game_args *vars)
{
	int	i;

	i = -1;
	vars->win = NULL;
	vars->img->dc.coin = NULL;
	vars->img->dc.door = NULL;
	vars->img->dc.door_closed = NULL;
	vars->img->img = NULL;
	vars->img->wall->img = NULL;
	while (++i < 3)
	{
		vars->player->walk.down[i] = NULL;
		vars->player->walk.up[i] = NULL;
		vars->player->walk.left[i] = NULL;
		vars->player->walk.right[i] = NULL;
	}
	vars->map = NULL;
}

int	initialize(t_game_args *vars)
{
	vars->init = mlx_init();
	vars->img = malloc(sizeof(t_game_args));
	if (!vars->img)
		return (1);
	vars->img->wall = malloc(sizeof(t_image_vs));
	if (!vars->img->wall)
		return (free(vars->img), 1);
	vars->player = malloc(sizeof(t_game_args));
	if (!vars->player)
		return (free(vars->img->wall), free(vars->img), 1);
	vars->player->img = malloc(sizeof(t_image_vs));
	if (!vars->player->img)
		return (free(vars->img->wall), free(vars->img), free(vars->player), 1);
	vars->restart = 0;
	vars->player->moviment = 0;
	values_init(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game_args	*vars;
	int			i;

	if (argc != 2)
		return (ft_putstr_fd("Error.\n", STDERR_FILENO), -1);
	vars = malloc(sizeof(t_game_args));
	if (parse(vars, argv))
		return (EXIT_FAILURE);
	i = 0;
	while (vars->map[i])
		i++;
	vars->win = mlx_new_window(vars->init, vars->img->width
			* ft_strlen(vars->map[0]), vars->img->heigh * i, "so_long");
	map_gen(vars);
	mlx_hook(vars->win, 2, 1L << 0, &key, vars);
	mlx_hook(vars->win, 17, 1L << 0, &destroy, vars);
	mlx_loop_hook(vars->init, &game_ticks, vars);
	mlx_loop(vars->init);
	free_all(vars);
	return (0);
}
