/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:57:52 by etornay-          #+#    #+#             */
/*   Updated: 2023/10/26 17:50:13 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

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

	atexit(ft_leaks);
	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	if (argc != 2)
		return (ft_printf("Error\nIntrodúzcame uno\n"), EXIT_FAILURE);
	init_struct(game);
	if (check_map(game, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game->mlx = mlx_init(game->x * 50, game->y * 50, "Buscad a Robin", false);
	if (create_image(game) == EXIT_FAILURE)
		return (free_all(game), EXIT_FAILURE);
	init_game(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (free_all(game), EXIT_SUCCESS);
}

/* 	mlx_t* mlx = mlx_init(500, 500, "Test", true);
	mlx_texture_t* texture = mlx_load_png("./jhin1.png");
	mlx_texture_t* texture2 = mlx_load_png("./jhin2.png");
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	mlx_image_t* img2 = mlx_texture_to_image(mlx, texture2);
	// Display the image
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_image_to_window(mlx, img2, 50, 0);
	mlx_loop(mlx);

	// Optional, terminate will clean up any left overs, this is just to demonstrate.
	mlx_delete_image(mlx, img);
	mlx_delete_image(mlx, img2);
	mlx_terminate(mlx); */
