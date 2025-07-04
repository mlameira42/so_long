/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:39:55 by mlameira          #+#    #+#             */
/*   Updated: 2025/02/18 20:20:31 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_obj(t_game_args *vars);
void	close_window(t_game_args *vars);

void	free_all(t_game_args *vars)
{
	if (!vars->init)
		return ;
	free_obj(vars);
	if (vars->img->wall)
		free(vars->img->wall);
	if (vars->img)
		free(vars->img);
	if (vars->player->img)
		free(vars->player->img);
	if (vars->player)
		free(vars->player);
	close_window(vars);
}

void	free_plr(t_game_args *vars)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		if (vars->player->walk.down[i])
			mlx_destroy_image(vars->init, vars->player->walk.down[i]);
		if (vars->player->walk.up[i])
			mlx_destroy_image(vars->init, vars->player->walk.up[i]);
		if (vars->player->walk.left[i])
			mlx_destroy_image(vars->init, vars->player->walk.left[i]);
		if (vars->player->walk.right[i])
			mlx_destroy_image(vars->init, vars->player->walk.right[i]);
	}
}

void	free_obj(t_game_args *vars)
{
	int	i;

	if (vars->img->dc.coin)
		mlx_destroy_image(vars->init, vars->img->dc.coin);
	if (vars->img->dc.door)
		mlx_destroy_image(vars->init, vars->img->dc.door);
	if (vars->img->dc.door_closed)
		mlx_destroy_image(vars->init, vars->img->dc.door_closed);
	if (vars->img->img)
		mlx_destroy_image(vars->init, vars->img->img);
	if (vars->img->wall->img)
		mlx_destroy_image(vars->init, vars->img->wall->img);
	free_plr(vars);
	i = -1;
	if (!vars->map)
		return ;
	while (vars->map[++i])
		free(vars->map[i]);
	free(vars->map);
}

void	close_window(t_game_args *vars)
{
	if (vars->init && vars->win)
		mlx_destroy_window(vars->init, vars->win);
	mlx_destroy_display(vars->init);
	free(vars->init);
	free(vars);
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
	{
		free(arr[i]);
	}
	free(arr);
}
