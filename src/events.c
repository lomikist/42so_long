/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:06:32 by arsargsy          #+#    #+#             */
/*   Updated: 2024/03/18 23:06:33 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "keys.h"
#include <stdio.h>

int	on_key_hook_event(int key, t_engine *engine)
{
	if (key == KEY_W || key == KEY_S)
		move_vertical(engine, key);
	else if (key == KEY_A || key == KEY_D)
		move_horizontal(engine, key);
	else if (key == KEY_ESC || key == KEY_Q)
		on_destroy_exit(engine);
	if (engine->player.points == engine->symbols.coin_c)
		engine->player.door_flag = 1;
	return (0);
}

int	check_all_symbols(t_engine *engine)
{
	char	**map;
	int		i;
	int		j;
	int		flag;

	map = engine->game.map;
	flag = 1;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!(map[i][j] == '0' || map[i][j] == 'P'
			|| map[i][j] == 'C' || map[i][j] == 'E'
			|| map[i][j] == '1' || map[i][j] == 'X'))
				return (0);
		}
	}
	return (1);
}

int	check(t_engine *engine)
{
	if (check_lines(engine) == 0)
		close_window_free_and_exit(engine, "Line problem.");
	if (check_boarder(engine) == 0)
		close_window_free_and_exit(engine, "Boarder problem.");
	if (check_p_e_c(engine) == 0)
		close_window_free_and_exit(engine, "Symbol problem.");
	if (check_path(engine, engine->player.y, engine->player.x) == 0)
		close_window_free_and_exit(engine, "Path problem.");
	if (check_all_symbols(engine) == 0)
		close_window_free_and_exit(engine, "Use 0 1 P E C only.");
	return (1);
}

void	args_valid(int argc, char **argv)
{
	int		fd;
	char	*ext;
	int		len;

	if (argc != 2)
		error_message("Wrong count of arguments!");
	len = ft_strlen(argv[1]);
	if (len < 5)
		error_message("Wrong file name");
	ext = ft_substr(argv[1], len - 4, 4);
	if (ft_strncmp(ext, ".ber", 5) != 0)
		error_message("File extension must be \".ber\"!");
	free(ext);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_message("Can't open file!");
	close(fd);
}
