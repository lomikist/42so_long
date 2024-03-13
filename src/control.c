#include "checker.h"

void	move_horizontal(t_engine *engine, int key)
{
	t_player	*player;
	char		**map;

	player = &engine->player;
	map = engine->game.map;
	if ( key == KEY_A && map[player->y][player->x - 1] != '1')
	{
		map[player->y][player->x] = '0';
		player->x -= 1;
		map[player->y][player->x] = 'P';
	}
	else if (key == KEY_D && map[player->y][player->x + 1] != '1')
	{
		map[player->y][player->x] = '0';
		player->x += 1;
		map[player->y][player->x] = 'P';
	}
}

void	move_vertical(t_engine *engine, int key)
{
	t_player	*player;
	char		**map;

	player = &engine->player;
	map = engine->game.map;
	if ( key == KEY_W && map[player->y - 1][player->x] != '1')
	{
		map[player->y][player->x] = '0';
		player->y -= 1;
		map[player->y][player->x] = 'P';
	}
	else if (key == KEY_D && map[player->y + 1][player->x] != '1')
	{
		map[player->y][player->x] = '0';
		player->y += 1;
		map[player->y][player->x] = 'P';
	}
}