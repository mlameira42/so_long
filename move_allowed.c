/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_allowed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:12 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/03 15:31:12 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	updown_cases(t_game_args *vars, int dest, char *dir, char hit);
static int	leftrigth_cases(t_game_args *vars, int dest, char *dir, char hit);

int	ismove_allowed(t_game_args *vars, int dest, char *dir, char hit)
{
	if (!ft_memcmp(dir, "UP", ft_strlen(dir)) || !ft_memcmp(dir, "DOWN", \
		ft_strlen(dir)))
		return (updown_cases(vars, dest, dir, hit));
	else if (!ft_memcmp(dir, "LEFT", ft_strlen(dir)) || \
			!ft_memcmp(dir, "RIGHT", ft_strlen(dir)))
		return (leftrigth_cases(vars, dest, dir, hit));
	return (1);
}

static int	updown_cases(t_game_args *vars, int dest, char *dir, char hit)
{
	int	posx;

	posx = vars->player->img->x;
	if (vars->map[(dest + vars->player->img->heigh) / vars->img->heigh] \
	[posx / vars->img->width] == hit && !ft_memcmp(dir, "DOWN", ft_strlen(dir)))
		return (0);
	else if (vars->map[dest / vars->img->heigh][posx / vars->img->width] == hit)
		return (0);
	return (1);
}

static int	leftrigth_cases(t_game_args *vars, int dest, char *dir, char hit)
{
	int	posy;

	posy = vars->player->img->y;
	if (vars->map[posy / vars->img->heigh][(dest + vars->player->img->width)
		/ vars->img->width] == hit && !ft_memcmp(dir, "RIGHT", ft_strlen(dir)))
		return (0);
	else if (vars->map[posy / vars->img->heigh][dest / vars->img->width] == hit)
		return (0);
	return (1);
}
