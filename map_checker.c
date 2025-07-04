/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:24:10 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/13 09:47:52 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	getmap(char *filename, t_game_args *vars)
{
	char	*hld;
	char	*maphld;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 1)
		return (0);
	hld = get_next_line(fd);
	maphld = NULL;
	while (hld)
	{
		if (hld[0] == '\n')
			return (free(hld), free(maphld), 0);
		maphld = get_lines(maphld, hld, '\0');
		free(hld);
		hld = get_next_line(fd);
	}
	if (!ft_strrchr(maphld, 'P') || !ft_strrchr(maphld, 'E')
		|| !ft_strrchr(maphld, 'C'))
		return (close(fd), free(maphld), 0);
	vars->map = NULL;
	vars->map = ft_split(maphld, '\n');
	free(maphld);
	close(fd);
	return (1);
}

int	checkwalls(t_game_args *vars)
{
	int		i;
	size_t	width;
	int		j;

	i = -1;
	width = ft_strlen(vars->map[0]);
	while (vars->map[0][++i])
		if (vars->map[0][i] != '1')
			return (0);
	i = -1;
	while (vars->map[++i])
	{
		if (ft_strlen(vars->map[i]) != width || (vars->map[i][0] != '1' \
				|| vars->map[i][ft_strlen(vars->map[i]) - 1] != '1'))
			return (0);
	}
	i--;
	j = -1;
	while (vars->map[i][++j])
		if (vars->map[i][j] != '1')
			return (0);
	return (1);
}

int	ismapvalid(char *filename, t_game_args *vars)
{
	int	i;
	int	j;

	if (!ft_strnstr(filename, ".ber", ft_strlen(filename)) || !getmap(filename,
			vars) || !checkwalls(vars))
		return (0);
	i = -1;
	vars->amount = 0;
	while (vars->map[++i])
	{
		j = -1;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] == '1' || vars->map[i][j] == '0'
				|| vars->map[i][j] == 'P' || vars->map[i][j] == 'C'
				|| vars->map[i][j] == 'E')
			{
				if (vars->map[i][j] == 'P')
					vars->amount++;
			}
			else
				return (0);
		}
	}
	return (1);
}
