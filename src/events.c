#include "checker.h"
#include "keys.h"
void	move_vertical(t_engine *engine, int key);
void	move_horizontal(t_engine *engine, int key);

int	on_key_hook_event(int key, t_engine *engine)
{
	if (key == KEY_W || key == KEY_S)
		move_vertical(engine, key);
	else if (key == KEY_A || key == KEY_D)
		move_horizontal(engine, key);
	if (engine->player.points == engine->symbols.coin_c)
		engine->player.door_flag = 1;	
	return (0);
}

