#include "checker.h"
#include "keys.h"

// void	move(t_engine *engine, int key)
// {
// 	t_player	*player;
// 	char		**map;

// 	player = &engine->player;
// 	map = engine->game.map;
// 	if (key == KEY_A && map[player->y][player->x - 1] != '1') {
// 		map[player->y][player->x] = '0';
// 		player->x -= 1;
// 	}
// 	else if (key == KEY_D && map[player->y][player->x + 1] != '1') {
// 		map[player->y][player->x] = '0';
// 		player->x += 1;
// 	}
// 	else if (key == KEY_W && map[player->y - 1][player->x] != '1') {
// 		map[player->y][player->x] = '0';
// 		player->y -= 1;
// 	}
// 	else if (key == KEY_S && map[player->y + 1][player->x] != '1') {
// 		map[player->y][player->x] = '0';
// 		player->y += 1;
// 	}
// 	if (map[player->y][player->x] == 'C')
// 		player->points += 1;
// 	map[player->y][player->x] = 'P';
// 	player->img_flag = !player->img_flag;
// }
void	move_horizontal(t_engine *engine, int key)
{
	t_player	*player;
	char		**map;

	player = &engine->player;
	map = engine->game.map;
	if ( key == KEY_A && map[player->y][player->x - 1] != '1')
	{
		if (map[player->y][player->x - 1] == 'C')
			player->points += 1;
		map[player->y][player->x] = '0';
		player->x -= 1;
		map[player->y][player->x] = 'P';
		player->move_count++;
	}
	else if (key == KEY_D && map[player->y][player->x + 1] != '1')
	{
		if (map[player->y][player->x + 1] == 'C')
			player->points += 1;
		map[player->y][player->x] = '0';
		player->x += 1;
		map[player->y][player->x] = 'P';
		player->move_count++;
	}
	player->img_flag = !player->img_flag;
}

void	move_vertical(t_engine *engine, int key)
{
	t_player	*player;
	char		**map;

	player = &engine->player;
	map = engine->game.map;
	if ( key == KEY_W && map[player->y - 1][player->x] != '1')
	{
		if (map[player->y - 1][player->x] == 'C')
			player->points += 1;
		map[player->y][player->x] = '0';
		player->y -= 1;
		map[player->y][player->x] = 'P';
		player->move_count++;
	}
	else if (key == KEY_S && map[player->y + 1][player->x] != '1')
	{
		if (map[player->y + 1][player->x] == 'C')
			player->points += 1;
		map[player->y][player->x] = '0';
		player->y += 1;
		map[player->y][player->x] = 'P';
		player->move_count++;
	}
	player->img_flag = !player->img_flag;
}
