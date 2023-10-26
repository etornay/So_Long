/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:07:24 by etornay-          #+#    #+#             */
/*   Updated: 2023/10/26 18:10:27 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_textures(t_game *g)
{
	mlx_delete_texture(g->t_suelo);
	mlx_delete_texture(g->t_muro);
	mlx_delete_texture(g->t_p1);
	mlx_delete_texture(g->t_p2);
	mlx_delete_texture(g->t_c);
	mlx_delete_texture(g->t_e1);
	mlx_delete_texture(g->t_e2);
}

int	create_image(t_game *g)
{
	g->t_suelo = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/s.png");
	g->t_muro = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/m.png");
	g->t_p1 = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/p1.png");
	g->t_p2 = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/p2.png");
	g->t_c = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/c.png");
	g->t_e1 = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/e1.png");
	g->t_e2 = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/e2.png");
	g->i_suelo = mlx_texture_to_image(g->mlx, g->t_suelo);
	g->i_muro = mlx_texture_to_image(g->mlx, g->t_muro);
	g->i_p1 = mlx_texture_to_image(g->mlx, g->t_p1);
	g->i_p2 = mlx_texture_to_image(g->mlx, g->t_p2);
	g->i_c = mlx_texture_to_image(g->mlx, g->t_c);
	g->i_e1 = mlx_texture_to_image(g->mlx, g->t_e1);
	g->i_e2 = mlx_texture_to_image(g->mlx, g->t_e2);
	if (!g->t_suelo || !g->t_muro || !g->t_p1 || !g->t_p2 || !g->t_c
		|| !g->t_e1 || !g->t_e2 || !g->i_suelo || !g->i_muro || !g->i_p1
		|| !g->i_p2 || !g->i_c || !g->i_e1 || !g->i_e2)
		return (EXIT_FAILURE);
	clean_textures(g);
	return (EXIT_SUCCESS);
}

void	init_game(t_game *g)
{
	while (g->map[g->z])
	{
		g->i = 0;
		while (g->map[g->z][g->i])
		{
			if (g->map[g->z][g->i] == '1')
				mlx_image_to_window(g->mlx, g->i_muro, g->i * 50, g->z * 50);
			if (g->map[g->z][g->i] == '0')
				mlx_image_to_window(g->mlx, g->i_suelo, g->i * 50, g->z * 50);
			if (g->map[g->z][g->i] == 'P')
			{
				mlx_image_to_window(g->mlx, g->i_suelo, g->i * 50, g->z * 50);
				mlx_image_to_window(g->mlx, g->i_p2, g->i * 50, g->z * 50);
			}
			if (g->map[g->z][g->i] == 'C')
			{
				mlx_image_to_window(g->mlx, g->i_suelo, g->i * 50, g->z * 50);
				mlx_image_to_window(g->mlx, g->i_c, g->i * 50, g->z * 50);
			}
			if (g->map[g->z][g->i] == 'E')
			{
				mlx_image_to_window(g->mlx, g->i_suelo, g->i * 50, g->z * 50);
				mlx_image_to_window(g->mlx, g->i_e2, g->i * 50, g->z * 50);
			}
			g->i++;
		}
		g->z++;
	}
}
