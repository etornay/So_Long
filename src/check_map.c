/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:34:02 by etornay-          #+#    #+#             */
/*   Updated: 2023/10/26 15:34:47 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *aber)
{
	int	i;

	i = ft_strlen(aber);
	if (aber[i - 1] == 'r' && aber[i - 2] == 'e'
		&& aber[i - 3] == 'b' && aber[i - 4] == '.')
		return (EXIT_SUCCESS);
	else
		return (ft_printf("Error\nNo funsiona, tronco\n"), EXIT_FAILURE);
}

int	lines_and_walls(t_game *game)
{
	game->i = 0;
	game->counter = ft_strlen(game->map[game->i]);
	while (game->map[game->i])
	{
		if (ft_strlen(game->map[game->i]) != (size_t)game->counter)
			return (ft_printf("Error\nNos mide diferente\n"), EXIT_FAILURE);
		game->i++;
	}
	game->counter = 0;
	while (game->map[game->counter] != NULL)
	{
		game->i = 0;
		while (game->map[game->counter][game->i])
		{
			if (game->map[0][game->i] != '1'
				|| game->map[game->y - 1][game->i] != '1')
			{
				return (ft_printf("Error\nContra el muro\n"), EXIT_FAILURE);
			}
			game->i++;
		}
		game->counter++;
	}
	return (EXIT_SUCCESS);
}

int	other_walls(t_game *game)
{
	game->i = 1;
	while (game->map[game->i] && game->i < game->y - 1)
	{
		if (game->map[game->i][0] != '1'
			|| game->map[game->i][game->x - 1] != '1')
		{
			return (ft_printf("Error\nContra el muro\n"), EXIT_FAILURE);
		}
		game->i++;
	}
	return (EXIT_SUCCESS);
}

int	things(t_game *game)
{
	game->i = -1;
	while (game->map[++game->i])
	{
		game->counter = -1;
		while (game->map[game->i][++game->counter])
		{
			if (game->map[game->i][game->counter] == 'P')
			{
				game->player.y = game->i;
				game->player.x = game->counter;
				game->c_player++;
			}
			if (game->map[game->i][game->counter] == 'E')
			{
				game->exit.y = game->i;
				game->exit.x = game->counter;
				game->c_exit++;
			}
			if (game->map[game->i][game->counter] == 'C')
				game->c_collect++;
		}
	}
	if (game->c_player != 1 || game->c_exit != 1 || game->c_collect < 1)
		return (ft_printf("Error\nElementos inválidos\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
