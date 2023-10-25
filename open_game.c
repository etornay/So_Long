/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:07:24 by etornay-          #+#    #+#             */
/*   Updated: 2023/10/25 15:31:09 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	init_image(t_game *g)
{
	g->t_suelo = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/s.png");
	g->t_muro = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/m.png");
	g->t_p1 = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/p1.png");
	g->t_p2 = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/p2.png");
	g->t_c = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/c.png");
	g->t_e1 = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/e1.png");
	g->t_e2 = mlx_load_png("/Users/etornay-/Desktop/so_long/sprites/e2.png");
}
