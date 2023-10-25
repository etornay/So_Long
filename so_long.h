/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:54:43 by etornay-          #+#    #+#             */
/*   Updated: 2023/10/25 15:29:15 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include "./Libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

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
	int				counter;
	t_position		player;
	t_position		exit;
	int				c_player;
	int				c_exit;
	int				c_collect;
	int				c_collect_copy;
	int				c_exit_copy;
	char			**map_copy;
	mlx_texture_t	*t_suelo;
	mlx_image_t		*i_suelo;
	mlx_texture_t	*t_muro;
	mlx_image_t		*i_muro;
	mlx_texture_t	*t_player1;
	mlx_image_t		*i_player1;
	mlx_texture_t	*t_player2;
	mlx_image_t		*i_player2;
	mlx_texture_t	*t_open;
	mlx_image_t		*i_open;
	mlx_texture_t	*t_close;
	mlx_image_t		*i_close;
	mlx_texture_t	*t_llave;
	mlx_image_t		*i_llave;
}	t_game;

void	init_struct(t_game *game);
int		read_map(char **argv, t_game *game);
void	free_all(t_game *game);
int		check_map(char *aber);
int		lines_and_walls(t_game *game);
int		other_walls(t_game *game);
int		things(t_game *game);
void	flood_fill(t_game *game, t_position	player, t_position size);
int		valid_way(t_game *game);
#endif