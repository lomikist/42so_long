#include "../includes/get_next_line.h" 
#include <fcntl.h>
#include "checker.h"

#define BLOCK_SIZE 70

void	error_message(char *text, int mode);

char	**read_map(int fd)
{
	char	**result;
	char	*one_line;
	char	*file_summary;
	int		i;

	i = 0;
	one_line = get_next_line(fd);
	while (one_line)
	{
		if (i == 0)
			file_summary = ft_strdup((const char *)one_line);
		else
		{
			one_line = get_next_line(fd);
			if (one_line)
				file_summary = ft_strjoin_gnl(file_summary, one_line);
		}
		free(one_line);
		i++;
	}
	result = ft_split(file_summary, '\n');
	free(file_summary);
	return (result);
}

void	set_up_game(t_engine *engine)
{
	int				i;
	int				fd;

	i = 0;
	fd = open("./maps/map.bar", O_RDONLY);
	engine->game.map = read_map(fd);
	close(fd);
	fd = open("./maps/map.bar", O_RDONLY);
	engine->game.map_cp = read_map(fd);
	close(fd);
	while (engine->game.map[i])
		i++;
	engine->game.m_h = i;
	i = 0;
	while (engine->game.map[0][i])
		i++;
	engine->game.m_w = i;
}

void	set_symbols_count(t_engine *engine)
{
	t_symbols	*symbols;
	char		**map;
	int			i;
	int			j;

	symbols = &engine->symbols;
	map = engine->game.map_cp;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				symbols->player_c++;
			else if (map[i][j] == 'E')
				symbols->exit_c++;
			else if (map[i][j] == 'C')
				symbols->coin_c++;
			else if (map[i][j] == 'X')
				symbols->enemy_c++;
		}
	}
}



void	set_mlx(t_engine *engine)
{
	engine->mlx = mlx_init();
	if (!engine->mlx)
		error_message("[MLX ERROR]: can't do mlx_init!\n", 1);
	engine->window = mlx_new_window(engine->mlx, engine->game.m_w * BLOCK_SIZE, \
					engine->game.m_h * BLOCK_SIZE, "SOOOO LONG");
	
}

void	set_imgs(t_engine *engine)
{
	int		width = 50;
	int		height = 50;
	t_imgs	*imgs;

	imgs = &engine->imgs;
	imgs->p_1 = mlx_xpm_file_to_image(engine->mlx, \
				"./xpm/player.xpm", &width, &height);
	imgs->coin_1 = mlx_xpm_file_to_image(engine->mlx, \
				"./xpm/coin.xpm", &width, &height);
	imgs->enemy_1 = mlx_xpm_file_to_image(engine->mlx, \
				"./xpm/enemy.xpm", &width, &height);
	imgs->wall = mlx_xpm_file_to_image(engine->mlx, \
				"./xpm/wall.xpm", &width, &height);
	imgs->bg = mlx_xpm_file_to_image(engine->mlx, \
				"./xpm/bg.xpm", &width, &height);
}

// void	put_img(int *arr, char symbol, t_engine *game, int *switcher)
// {
// 	int	i;
// 	int	j;
// 	t_game *game;

// 	game = engine->game;
// 	i = arr[0];
// 	j = arr[1];
// 	if (symbol == Wall)
// 		mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall, j, i);
// 	else if (symbol == Empty)
// 		mlx_put_image_to_window(game->mlx, game->win, game->imgs.bg, j, i);
// 	else if (symbol == Coin && *switcher < SWITCH / 2)
// 		mlx_put_image_to_window(game->mlx, game->win, game->imgs.coin_1, j, i);
// 	else if (symbol == Coin && *switcher < SWITCH)
// 		mlx_put_image_to_window(game->mlx, game->win, game->imgs.coin_2, j, i);
// 	else if (symbol == Enemy && *switcher < SWITCH / 2)
// 		mlx_put_image_to_window(game->mlx, game->win, game->imgs.enemy_1, j, i);
// 	else if (symbol == Enemy && *switcher < SWITCH)
// 		mlx_put_image_to_window(game->mlx, game->win, game->imgs.enemy_2, j, i);
// 	else if (symbol == Exit && game->map.coin == game->c_collect)
// 		mlx_put_image_to_window(game->mlx, game->win, game->imgs.e_open, j, i);
// 	else if (symbol == Exit)
// 		mlx_put_image_to_window(game->mlx, game->win, game->imgs.e_close, j, i);
// 	else if (symbol == Player && *switcher < SWITCH / 2)
// 		mlx_put_image_to_window(game->mlx, game->win, game->imgs.p_1, j, i);
// 	else if (symbol == Player && *switcher < SWITCH)
// 		mlx_put_image_to_window(game->mlx, game->win, game->imgs.p_2, j, i);
// }
void	draw_block(t_engine *engine, char symbol, int i, int j)
{
	if (symbol == '1')
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.wall, j, i);
	else if (symbol == 'X')
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.bg, j, i);
	else if (symbol == 'C')
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.coin_1, j, i);
	else if (symbol == 'C')
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.coin_2, j, i);
	else if (symbol == 'X')
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.enemy_1, j, i);
	else if (symbol == 'E' && engine->symbols.coin_c == engine->)
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.e_open, j, i);
	else if (symbol == 'P')
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.p_2, j, i);
}

void	draw_game(t_engine *engine)
{
	int	i;
	int j;
	char **map;
	int	x;
	int	y;

	map = engine->game.map;
	i = -1;
	j = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			x = j * BLOCK_SIZE;
			y = i * BLOCK_SIZE;
			draw_block(engine, map[i][j], x, y);
		}
	}
}

int	main(void)
{
	t_engine	engine;

	set_up_game(&engine);
	set_symbols_count(&engine);
	check(&engine);
	set_mlx(&engine);
	set_imgs(&engine);
	draw_game(&engine);
	// draw(engine.game->map);
	mlx_loop(engine.mlx);
	return (0);
}
