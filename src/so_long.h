/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:54:43 by etornay-          #+#    #+#             */
/*   Updated: 2023/11/06 13:55:44 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_game
{
	char			**map;
	int				y;
	int				x;
	int				i;
	int				j;
	int				z;
	int				moves;
	t_position		player;
	t_position		exit;
	int				c_player;
	int				c_exit;
	int				c_collect;
	int				c_collect_copy;
	int				c_exit_copy;
	char			**map_copy;
	mlx_texture_t	*t_s;
	mlx_image_t		*i_s;
	mlx_texture_t	*t_m;
	mlx_image_t		*i_m;
	mlx_texture_t	*t_p1;
	mlx_image_t		*i_p1;
	mlx_texture_t	*t_pu;
	mlx_image_t		*i_pu;
	mlx_texture_t	*t_pl;
	mlx_image_t		*i_pl;
	mlx_texture_t	*t_pr;
	mlx_image_t		*i_pr;
	mlx_texture_t	*t_e2;
	mlx_image_t		*i_e2;
	mlx_texture_t	*t_e1;
	mlx_image_t		*i_e1;
	mlx_texture_t	*t_c;
	mlx_image_t		*i_c;
	mlx_t			*mlx;
}	t_game;

void	init_struct(t_game *game);
int		read_map(char **argv, t_game *game);
void	free_all(t_game *game);
int		check_extension(char *aber);
int		lines_and_walls(t_game *game);
int		other_walls(t_game *game);
int		things(t_game *game);
void	flood_fill(t_game *game, t_position	player, t_position size);
int		valid_way(t_game *game);
int		create_image(t_game *g);
void	init_game(t_game *g);
void	close_game(void *p);
void	keyhook(mlx_key_data_t keydata, void *p);
#endif