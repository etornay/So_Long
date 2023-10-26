/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:54:43 by etornay-          #+#    #+#             */
/*   Updated: 2023/10/26 16:03:21 by etornay-         ###   ########.fr       */
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
/* gcc -Wall -Werror -Wextra Libft/libft.a MLX42/libmlx42.a -Iinclude -lglfw -L '/Users/etornay-/.brew/opt/glfw/lib/' *.c -o so_long */
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
	int				z;
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
	mlx_texture_t	*t_p1;
	mlx_image_t		*i_p1;
	mlx_texture_t	*t_p2;
	mlx_image_t		*i_p2;
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
#endif