/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:06:25 by arsargsy          #+#    #+#             */
/*   Updated: 2024/03/18 23:06:26 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	draw_block(t_engine *engine, char symbol, int i, int j)
{
	mlx_put_image_to_window(engine->mlx, \
		engine->window, engine->imgs.grass, i, j);
	if (symbol == '1')
		mlx_put_image_to_window(engine->mlx, \
			engine->window, engine->imgs.wall, i, j);
	else if (symbol == 'P' && engine->player.img_flag)
		mlx_put_image_to_window(engine->mlx, \
			engine->window, engine->imgs.p_1, i, j);
	else if (symbol == 'P' && !engine->player.img_flag)
		mlx_put_image_to_window(engine->mlx, \
			engine->window, engine->imgs.p_2, i, j);
	else if (symbol == 'C')
		mlx_put_image_to_window(engine->mlx, \
			engine->window, engine->imgs.coin, i, j);
	else if (symbol == 'E' && !engine->player.door_flag)
		mlx_put_image_to_window(engine->mlx, \
			engine->window, engine->imgs.door_2, i, j);
	else if (symbol == 'E' && engine->player.door_flag)
		mlx_put_image_to_window(engine->mlx, \
			engine->window, engine->imgs.door_1, i, j);
	else if (symbol == 'X')
		mlx_put_image_to_window(engine->mlx, \
			engine->window, engine->imgs.enemy, i, j);
}

void	draw_points(t_engine *engine)
{
	char	*point;
	char	*moves;

	point = ft_itoa(engine->player.points);
	moves = ft_itoa(engine->player.move_count);
	mlx_string_put(engine->mlx, engine->window, \
	50, 20, 0x00FFFFFF, "Move count - ");
	mlx_string_put(engine->mlx, engine->window, 135, 20, 0x00FFFFFF, moves);
	mlx_string_put(engine->mlx, engine->window, \
	50, 50, 0x00FFFFFF, "Points count - ");
	mlx_string_put(engine->mlx, engine->window, 155, 50, 0x00FFFFFF, point);
	free(point);
	free(moves);
}

int	draw_game(t_engine *engine)
{
	int		i;
	int		j;
	char	**map;
	int		x;
	int		y;

	map = engine->game.map;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			x = j * BLOCK_SIZE;
			y = i * BLOCK_SIZE;
			draw_block(engine, map[i][j], x, y);
			draw_points(engine);
		}
	}
	return (0);
}
