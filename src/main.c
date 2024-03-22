/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:07:29 by arsargsy          #+#    #+#             */
/*   Updated: 2024/03/18 23:07:34 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h" 
#include "checker.h"

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

void	set_up_game(t_engine *engine, char **argv)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	engine->game.map = read_map(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
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
	engine->player.move_count = 0;
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

void	set_imgs(t_engine *eng)
{
	int		width;
	t_imgs	*imgs;

	width = 50;
	imgs = &eng->imgs;
	imgs->p_1 = mlx_xpm_file_to_image(eng->mlx,
			"./xpm/player_1.xpm", &width, &width);
	imgs->p_2 = mlx_xpm_file_to_image(eng->mlx,
			"./xpm/player_2.xpm", &width, &width);
	imgs->coin = mlx_xpm_file_to_image(eng->mlx,
			"./xpm/coin.xpm", &width, &width);
	imgs->coin2 = mlx_xpm_file_to_image(eng->mlx,
			"./xpm/coin2.xpm", &width, &width);
	imgs->enemy1 = mlx_xpm_file_to_image(eng->mlx,
			"./xpm/enemy.xpm", &width, &width);
	imgs->enemy2 = mlx_xpm_file_to_image(eng->mlx,
			"./xpm/enemy2.xpm", &width, &width);
	imgs->wall = mlx_xpm_file_to_image(eng->mlx,
			"./xpm/wall.xpm", &width, &width);
	imgs->grass = mlx_xpm_file_to_image(eng->mlx,
			"./xpm/grass.xpm", &width, &width);
	imgs->door_1 = mlx_xpm_file_to_image(eng->mlx,
			"./xpm/door_1.xpm", &width, &width);
	imgs->door_2 = mlx_xpm_file_to_image(eng->mlx,
			"./xpm/door_2.xpm", &width, &width);
}

int	main(int argc, char **argv)
{
	t_engine	engine;

	args_valid(argc, argv);
	set_up_game(&engine, argv);
	engine.symbols.player_c = 0;
	engine.symbols.exit_c = 0;
	engine.symbols.coin_c = 0;
	engine.symbols.enemy_c = 0;
	set_symbols_count(&engine);
	engine.mlx = mlx_init();
	if (!engine.mlx)
		error_message("Can't do mlx_init!\n");
	engine.window = mlx_new_window(engine.mlx, engine.game.m_w * BLOCK_SIZE, \
					engine.game.m_h * BLOCK_SIZE, "SO LONG");
	set_imgs(&engine);
	if (check(&engine) == 0)
		exit(EXIT_SUCCESS);
	mlx_loop_hook(engine.mlx, draw_game, &engine);
	mlx_key_hook(engine.window, on_key_hook_event, &engine);
	mlx_hook(engine.window, 17, 0, on_destroy_exit, &engine);
	mlx_loop(engine.mlx);
	return (0);
}
