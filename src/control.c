/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:06:18 by arsargsy          #+#    #+#             */
/*   Updated: 2024/03/18 23:06:19 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "keys.h"

void	move_horizontal(t_engine *engine, int key)
{
	t_player	*p;
	char		**map;
	int			new_x;

	new_x = 0;
	map = engine->game.map;
	p = &engine->player;
	if (key == KEY_A)
		new_x = p->x - 1;
	else if (key == KEY_D)
		new_x = p->x + 1;
	if (map[p->y][new_x] == '1' || (map[p->y][new_x] == 'E'
			&& p->points != engine->symbols.coin_c))
		return ;
	if (map[p->y][new_x] == 'C')
		p->points++;
	else if (map[p->y][new_x] == 'X')
		close_window_free_and_exit(engine, "be more smart in next time.");
	else if (map[p->y][new_x] == 'E')
		close_window_free_and_exit(engine, "you won the game");
	map[p->y][p->x] = '0';
	p->x = new_x;
	map[p->y][p->x] = 'P';
	p->move_count++;
	p->img_flag = !p->img_flag;
}

void	move_vertical(t_engine *engine, int key)
{
	t_player	*player;
	char		**map;
	int			new_y;

	new_y = 0;
	map = engine->game.map;
	player = &engine->player;
	if (key == KEY_W)
		new_y = player->y - 1;
	else if (key == KEY_S)
		new_y = player->y + 1;
	if (map[new_y][player->x] == '1' || (map[new_y][player->x] == 'E'
		&& player->points != engine->symbols.coin_c))
		return ;
	if (map[new_y][player->x] == 'C')
		player->points++;
	else if (map[new_y][player->x] == 'X')
		close_window_free_and_exit(engine, "Be more smart in next time.");
	else if (map[new_y][player->x] == 'E')
		close_window_free_and_exit(engine, "You won the game");
	map[player->y][player->x] = '0';
	player->y = new_y;
	map[player->y][player->x] = 'P';
	player->move_count++;
	player->img_flag = !player->img_flag;
}
