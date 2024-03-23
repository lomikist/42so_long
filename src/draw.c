/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:06:25 by arsargsy          #+#    #+#             */
/*   Updated: 2024/03/22 22:32:02 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	draw_block(t_engine *eng, char symbol, int i, int j)
{
	mlx_put_image_to_window(eng->mlx, eng->window, eng->imgs.grass, i, j);
	if (symbol == '1')
		mlx_put_image_to_window(eng->mlx, eng->window, eng->imgs.wall, i, j);
	else if (symbol == 'P' && eng->player.img_flag)
		mlx_put_image_to_window(eng->mlx, eng->window, eng->imgs.p_1, i, j);
	else if (symbol == 'P' && !eng->player.img_flag)
		mlx_put_image_to_window(eng->mlx, eng->window, eng->imgs.p_2, i, j);
	else if (symbol == 'C' && eng->frame_count % 70 > 35)
		mlx_put_image_to_window(eng->mlx, eng->window, eng->imgs.coin, i, j);
	else if (symbol == 'C' && eng->frame_count % 70 < 35)
		mlx_put_image_to_window(eng->mlx, eng->window, eng->imgs.coin2, i, j);
	else if (symbol == 'E' && !eng->player.door_flag)
		mlx_put_image_to_window(eng->mlx, eng->window, eng->imgs.door_2, i, j);
	else if (symbol == 'E' && eng->player.door_flag)
		mlx_put_image_to_window(eng->mlx, eng->window, eng->imgs.door_1, i, j);
	else if (symbol == 'X' && eng->frame_count % 70 > 35)
		mlx_put_image_to_window(eng->mlx, eng->window, eng->imgs.enemy1, i, j);
	else if (symbol == 'X' && eng->frame_count % 70 < 35)
		mlx_put_image_to_window(eng->mlx, eng->window, eng->imgs.enemy2, i, j);
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
	int			i;
	int			j;
	char		**map;

	map = engine->game.map;
	engine->frame_count++;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			draw_block(engine, map[i][j], j * BLOCK_SIZE, i * BLOCK_SIZE);
			draw_points(engine);
		}
	}
	return (0);
}
