/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:35:20 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/13 10:45:32 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse(t_game_args *vars, char **argv)
{
	if (initialize(vars))
		return (ft_putstr_fd("Error\n", STDERR_FILENO), 1);
	if (!ismapvalid(argv[1], vars) || !has_path(vars) || \
		loadimg(vars) || !player_spwan(vars) || vars->amount != 1)
		return (free_all(vars), ft_putstr_fd("Error.\n", STDERR_FILENO), 1);
	if (ismap_toobig(vars))
		return (free_all(vars), ft_putstr_fd("Error.\n", STDERR_FILENO), 1);
	return (0);
}
