/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funciones.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:02:40 by etornay-          #+#    #+#             */
/*   Updated: 2023/10/25 14:40:12 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_game *game)
{
	game->i = 0;
	if (game->map != NULL)
	{
		while (game->map[game->i] != NULL)
			free(game->map[game->i++]);
		free(game->map);
	}
	game->i = 0;
	if (game->map_copy != NULL)
	{
		while (game->map_copy[game->i] != NULL)
			free(game->map_copy[game->i++]);
		free(game->map_copy);
	}
	free(game);
}

void	flood_fill(t_game *game, t_position	player, t_position size)
{
	if (player.x >= size.x || player.y >= size.y || player.x < 0
		|| player.y < 0 || game->map_copy[player.y][player.x] == '1'
		|| game->map_copy[player.y][player.x] == '@')
		return ;
	if (game->map_copy[player.y][player.x] == 'C')
		game->c_collect_copy++;
	if (game->map_copy[player.y][player.x] == 'E')
	{
		game->c_exit_copy++;
		game->exit.x = player.x;
		game->exit.y = player.y;
	}
	game->map_copy[player.y][player.x] = '@';
	flood_fill(game, (t_position){player.x + 1, player.y}, size);
	flood_fill(game, (t_position){player.x - 1, player.y}, size);
	flood_fill(game, (t_position){player.x, player.y + 1}, size);
	flood_fill(game, (t_position){player.x, player.y - 1}, size);
}

int	valid_way(t_game *game)
{
	flood_fill(game, game->player, (t_position){game->x, game->y});
	if (game->c_collect_copy != game->c_collect
		|| game->c_exit != game->c_exit_copy)
		return (ft_printf("Error\nMe he desviao\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
