#include "checker.h"
#include "keys.h"
void	move(t_engine *engine, int key);
void	close_window_free_and_exit(t_engine *engine);

int	on_key_hook_event(int key, t_engine *engine)
{
	if (key == KEY_W || key == KEY_S 
		|| key == KEY_A || key == KEY_D)
		move(engine, key);
	else if (key == KEY_ESC)
		close_window_free_and_exit(engine);
	return (0);
}

