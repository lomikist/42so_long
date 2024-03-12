#include "checker.h"
#include "keys.h"

void	move_up(t_engine *engine)
{
	t_player	*player;
	char		**map;

	player = &engine->player;
	map = engine->game.map;
	if (map[player->y - 1][player->x] != '1')
	{
		map[player->y][player->x] = '0';
		player->y -= 1;
		map[player->y][player->x] = 'P';
	}
}

void	move_down(t_engine *engine)
{
	t_player	*player;
	char		**map;

	player = &engine->player;
	map = engine->game.map;
	if (map[player->y + 1][player->x] != '1')
	{
		map[player->y][player->x] = '0';
		player->y += 1;
		map[player->y][player->x] = 'P';
	}
}

void	move_left(t_engine *engine)
{
	t_player	*player;
	char		**map;

	player = &engine->player;
	map = engine->game.map;
	if (map[player->y][player->x - 1] != '1')
	{
		map[player->y][player->x] = '0';
		player->x -= 1; 
		map[player->y][player->x] = 'P';
	}
}

void	move_right(t_engine *engine)
{
	t_player	*player;
	char		**map;

	player = &engine->player;
	map = engine->game.map;
	if (map[player->y][player->x + 1] != '1')
	{
		map[player->y][player->x] = '0';
		player->x += 1; 
		map[player->y][player->x] = 'P';
	}
}


int	on_key_hook_event(int key, t_engine *engine)
{
	if (key == KEY_W)
		move_up(engine);
	else if (key == KEY_S)
		move_down(engine);
	else if (key == KEY_A)
		move_left(engine);
	else if (key == KEY_D)
		move_right(engine);
	// else if (key == KEY_ESC)
	// 	on_destroy_event(engine);
	// draw_fractal(engine);
	return (0);
}

