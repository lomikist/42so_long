#include "../includes/get_next_line.h" 
#include <fcntl.h>
#include "checker.h"
#define WIN_SIZE 500

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
		// error_message("[MLX ERROR]: can't do mlx_init!\n", 1);
	engine->window = mlx_new_window(engine->mlx, WIN_SIZE, WIN_SIZE, \
												"blablabla");
}

int	main(void)
{
	t_engine	engine;

	set_up_game(&engine);
	set_symbols_count(&engine);
	set_mlx(&engine);
	check(&engine);
	// draw(engine.game->map);
	mlx_loop(engine.mlx);
	return (0);
}
