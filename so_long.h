/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlameira <mlameira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:09:39 by mlameira          #+#    #+#             */
/*   Updated: 2025/03/13 10:36:54 by mlameira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef SPEED
#  define SPEED 3
# endif

typedef struct image
{
	void			*img;
	int				x;
	int				y;
	int				heigh;
	int				width;
	struct			s_other
	{
		void		*door;
		void		*door_closed;
		int			dwidth;
		int			dheigh;
		void		*coin;
		int			coinw;
		int			coinh;
	} dc;
	struct image	*wall;
}					t_image_vs;

typedef struct cords
{
	int				x;
	int				y;
}					t_coords;

typedef struct directions
{
	char			*up;
	char			*down;
	char			*left;
	char			*right;
}					t_dirs;

typedef struct game
{
	void			*init;
	void			*win;
	void			*cont;
	char			**map;
	struct			s_mapstats
	{
		int			lines;
		int			cols;
	} maplc;
	int				restart;
	int				amount;
	int				moviment;
	struct			s_move
	{
		void		*up[3];
		void		*down[3];
		void		*left[3];
		void		*right[3];
	} walk;
	struct image	*img;
	struct game		*player;
}					t_game_args;
int					parse(t_game_args *vars, char **argv);
int					ismapvalid(char *filename, t_game_args *vars);
int					destroy(t_game_args *vars);
int					initialize(t_game_args *vars);
int					loadimg(t_game_args *vars);
int					movehandle(int key, t_game_args *vars, int dest);
int					ismove_allowed(t_game_args *vars, int dest, char *dir,
						char hit);
int					game_ticks(t_game_args *vars);
char				*get_next_line(int fd);
size_t				ft_addback(char *dst, char *src, size_t size, size_t len);
size_t				ft_cpy(char *dst, const char *src, size_t size);
char				*get_lines(char *dest, char *src, char tofind);
int					ft_findchr(char *s, char c);
int					map_gen(t_game_args *vars);
int					player_spwan(t_game_args *vars);
void				keyhit(t_game_args *vars, int key);
int					key(int keycode, t_game_args *vars);
char				*join_tostr(char *begin, char toadd, char *end);
void				free_all(t_game_args *vars);
int					has_path(t_game_args *vars);
void				free_arr(char **arr);
int					ismap_toobig(t_game_args *vars);
int					item_amount(char **map, char tofind);

#endif