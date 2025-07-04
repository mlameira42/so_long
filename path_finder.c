/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:53:02 by mlameira          #+#    #+#             */
/*   Updated: 2025/02/13 13:16:42 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_matrixdup(char **map, t_game_args *vars)
{
	char	**map2;
	int		i;
	int		j;

	i = 0;
	map2 = malloc(sizeof(char *) * (vars->maplc.cols + 1));
	while (i < vars->maplc.cols)
	{
		j = -1;
		map2[i] = malloc(sizeof(char) * vars->maplc.lines + 1);
		map2[i][vars->maplc.lines] = 0;
		while (++j < vars->maplc.lines)
			map2[i][j] = map[i][j];
		i++;
	}
	map2[vars->maplc.cols] = 0;
	return (map2);
}

void	f_fill(char **tab, t_coords size, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] == '1' || (tab[row][col] != 'P' && tab[row][col] != '0'
			&& tab[row][col] != 'C' && tab[row][col] != 'E'))
		return ;
	tab[row][col] = '1';
	f_fill(tab, size, row - 1, col);
	f_fill(tab, size, row + 1, col);
	f_fill(tab, size, row, col - 1);
	f_fill(tab, size, row, col + 1);
}

char	**flood_fill(char **tab, t_coords size, t_coords begin)
{
	f_fill(tab, size, begin.y, begin.x);
	return (tab);
}

int	path_finder(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P' || map[j][i] == 'C' || map[j][i] == 'E')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	has_path(t_game_args *vars)
{
	t_coords	size;
	t_coords	player;
	char		**map;

	player.x = -1;
	player.y = -1;
	vars->maplc.cols = -1;
	vars->maplc.lines = ft_strlen(vars->map[0]);
	while (vars->map[++vars->maplc.cols])
		;
	while (vars->map[++player.y])
	{
		player.x = -1;
		while (vars->map[player.y][++player.x]
			&& vars->map[player.y][player.x] != 'P')
			;
		if (vars->map[player.y][player.x] == 'P')
			break ;
	}
	size.x = vars->maplc.lines;
	size.y = vars->maplc.cols;
	map = ft_matrixdup(vars->map, vars);
	if (path_finder(flood_fill(map, size, player)))
		return (free_arr(map), 1);
	return (free_arr(map), 0);
}
