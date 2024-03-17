#include "../includes/get_next_line.h" 
#include "checker.h"


// void	error_message(char *text, int mode);
int		on_key_hook_event(t_engine *engine, int key);
void	error_message(char *sms)
{
	printf("%s\n", sms);
	exit(EXIT_FAILURE);
}

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
	engine->player.points = 0;
	engine->player.img_flag = 0;
	engine->player.door_flag = 0;
}

void	set_symbols_count(t_engine *engine)
{
	char		**map;
	int			i;
	int			j;

	map = engine->game.map_cp;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
			{
				engine->player.y = i;
				engine->player.x = j;
				engine->symbols.player_c++;
			}
			else if (map[i][j] == 'E')
				engine->symbols.exit_c++;
			else if (map[i][j] == 'C')
				engine->symbols.coin_c++;
			else if (map[i][j] == 'X')
				engine->symbols.enemy_c++;
		}
	}
}

void	set_mlx(t_engine *engine)
{
	engine->mlx = mlx_init();
	if (!engine->mlx)
		error_message("[MLX ERROR]: can't do mlx_init!\n");
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
				"./xpm/player_1.xpm", &width, &height);
	imgs->p_2 = mlx_xpm_file_to_image(engine->mlx, \
				"./xpm/player_2.xpm", &width, &height);
	imgs->coin = mlx_xpm_file_to_image(engine->mlx, \
				"./xpm/coin.xpm", &width, &height);
	imgs->enemy = mlx_xpm_file_to_image(engine->mlx, \
				"./xpm/enemy.xpm", &width, &height);
	imgs->wall = mlx_xpm_file_to_image(engine->mlx, \
				"./xpm/wall.xpm", &width, &width);
	imgs->grass = mlx_xpm_file_to_image(engine->mlx, \
				"./xpm/grass.xpm", &width, &width);
	imgs->door_1 = mlx_xpm_file_to_image(engine->mlx, \
				"./xpm/door_1.xpm", &width, &width);
	imgs->door_2 = mlx_xpm_file_to_image(engine->mlx, \
				"./xpm/door_2.xpm", &width, &width);
}

void	draw_block(t_engine *engine, char symbol, int i, int j)
{
	mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.grass, i, j);
	if (symbol == '1')
		mlx_put_image_to_window(engine->mlx ,engine->window, engine->imgs.wall, i, j);
	else if (symbol == 'P' && engine->player.img_flag)
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.p_1, i, j);
	else if (symbol == 'P' && !engine->player.img_flag)
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.p_2, i, j);
	else if (symbol == 'C')
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.coin, i, j);
	else if (symbol == 'E' && !engine->player.door_flag)
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.door_2, i, j);
	else if (symbol == 'E' && engine->player.door_flag)
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.door_1, i, j);
	else if (symbol == 'X')
		mlx_put_image_to_window(engine->mlx, engine->window, engine->imgs.enemy, i, j);
}

char	*ft_itoa(int n);
char	*ft_strjoin_gnl(char *s1, const char *s2);

void draw_points(t_engine *engine)
{
	char *point;
	char *moves;
	
	point = ft_itoa(engine->player.points);
	moves = ft_itoa(engine->player.move_count);
	mlx_string_put(engine->mlx, engine->window, 50, 20, 0x00FFFFFF, "Move count - ");
	mlx_string_put(engine->mlx, engine->window, 135, 20, 0x00FFFFFF, moves);
	mlx_string_put(engine->mlx, engine->window, 50, 50, 0x00FFFFFF, "Points count - ");
	mlx_string_put(engine->mlx, engine->window, 155, 50, 0x00FFFFFF, point);
	free(point);
	free(moves);
}


int	draw_game(t_engine *engine)
{
	int	i;
	int j;
	char **map;
	int	x;
	int	y;

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


void	map_free(int i, char **map)
{
	while (i >= 0)
	{
		free(map[i]);
		--i;
	}
	free(map);
}

void	close_window_free_and_exit(t_engine *engine, char *sms)
{
	mlx_destroy_window(engine->mlx, engine->window);
	map_free(engine->game.m_h, engine->game.map);
	map_free(engine->game.m_h, engine->game.map_cp);
	printf("You did %d moves\n", engine->player.move_count);
	error_message(sms);
}

int	on_destroy_exit(t_engine *engine)
{
	mlx_destroy_window(engine->mlx, engine->window);
	map_free(engine->game.m_h, engine->game.map);
	map_free(engine->game.m_h, engine->game.map_cp);
	printf("You left the game and did %d moves\n", engine->player.move_count);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	t_engine	engine;

	set_up_game(&engine);
	set_symbols_count(&engine);
	if (check(&engine) == 0)
		exit(EXIT_SUCCESS);
	set_mlx(&engine);
	set_imgs(&engine);
	mlx_loop_hook(engine.mlx, draw_game, &engine);
	mlx_key_hook(engine.window, on_key_hook_event, &engine);
	mlx_loop(engine.mlx);
	return (0);
}
