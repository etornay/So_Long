/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:57:52 by etornay-          #+#    #+#             */
/*   Updated: 2023/11/03 16:17:29 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* void	ft_leaks(void)
{
	system("leaks -q so_long");
} */
/* atexit(ft_leaks); */
/* gcc -Wall -Werror -Wextra Libft/libft.a MLX42/libmlx42.a -Iinclude -lglfw -L '/Users/etornay-/.brew/opt/glfw/lib/' *.c -o so_long */

static int	check_map(t_game *game, char **argv)
{
	if (check_extension(argv[1]) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (read_map(argv, game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (lines_and_walls(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (other_walls(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (things(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	if (valid_way(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	if (argc != 2)
		return (ft_printf("Error\nIntroduzca mapa, pls\n"), EXIT_FAILURE);
	init_struct(game);
	if (check_map(game, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game->mlx = mlx_init(game->x * 50, game->y * 50, "Buscad a Robin", false);
	if (create_image(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	init_game(game);
	mlx_key_hook(game->mlx, &keyhook, game);
	mlx_close_hook(game->mlx, &close_game, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (free_all(game), EXIT_SUCCESS);
}
