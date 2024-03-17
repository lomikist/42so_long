#include "checker.h"
#include "keys.h"
int	on_destroy_exit(t_engine *engine);
void	close_window_free_and_exit(t_engine *engine, char *sms);

void move_horizontal(t_engine *engine, int key)
{
    t_player	*player;
    char		**map;
    int			new_x;

	map = engine->game.map;
 	player = &engine->player;
    if (key == KEY_A)
        new_x = player->x - 1;
    else if (key == KEY_D)
        new_x = player->x + 1;
    else
        new_x = player->x;
    if (map[player->y][new_x] == '1' 
		|| (map[player->y][new_x] == 'E' && player->points != engine->symbols.coin_c))
        return;
    if (map[player->y][new_x] == 'C')
        player->points++;
    else if (map[player->y][new_x] == 'X')
        close_window_free_and_exit(engine, "be more smart in next time.");
	else if (map[player->y][new_x] == 'E')
		close_window_free_and_exit(engine, "you won the game");
    map[player->y][player->x] = '0';
    player->x = new_x;
    map[player->y][player->x] = 'P';
    player->move_count++;
    player->img_flag = !player->img_flag;
}

void move_vertical(t_engine *engine, int key)
{
    t_player *player;
    char **map;
    int new_y;

	map = engine->game.map;
 	player = &engine->player;
    if (key == KEY_W)
        new_y = player->y - 1;
    else if (key == KEY_S)
        new_y = player->y + 1;
    else
        return;
    if (map[new_y][player->x] == '1'
			|| (map[new_y][player->x] == 'E' && player->points != engine->symbols.coin_c))
        return;
	if (map[new_y][player->x] == 'C')
        player->points++;
    else if (map[new_y][player->x] == 'X')
        close_window_free_and_exit(engine, "be more smart in next time.");
	else if (map[new_y][player->x] == 'E')
		close_window_free_and_exit(engine, "you won the game");
	map[player->y][player->x] = '0';
    player->y = new_y;
    map[player->y][player->x] = 'P';
    player->move_count++;
    player->img_flag = !player->img_flag;
}
