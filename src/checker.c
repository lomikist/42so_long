#include "checker.h"
#include <stddef.h>
#include "../includes/get_next_line.h" 

int	check_dead_case(t_game *game, int y, int x)
{
	if ((game->map_cp[y + 1][x] == '1' || game->map_cp[y + 1][x] == '2')
		&& (game->map_cp[y - 1][x] == '1' || game->map_cp[y - 1][x] == '2')
		&& (game->map_cp[y][x + 1] == '1' || game->map_cp[y][x + 1] == '2')
		&& (game->map_cp[y][x - 1] == '1' || game->map_cp[y][x - 1] == '2'))
		return (1);
	else
		return (0);
}

int	check_path(t_game *game, int y, int x)
{
	if (game->map_cp[y][x] == 'E')
		return (1);
	if (game->map_cp[y][x] == '1')
		return (0);
	if (game->map_cp[y][x] == '2')
		return (0);
	game->map_cp[y][x] = '2';
	if (check_dead_case(game, y, x))
		game->map_cp[y][x] = '1';
	if (check_path(game, y - 1, x) || check_path(game, y, x - 1)
		|| check_path(game, y, x + 1) || check_path(game, y + 1, x))
		return (1);
	else
		return (0);
}

int	check_lines(t_game *game)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_boarder(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->m_w)
	{
		if (game->map[0][i] != '1'
			&& game->map[game->m_h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->m_h)
	{
		if (game->map[i][0] != '1'
			&& game->map[i][game->m_w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_p_e_c(t_symbols *symbols)
{
	if (symbols->exit_c == 1 && symbols->player_c == 1 && symbols->coin_c > 1)
		return (1);
	return (0);
}

int	check(t_engine *engine)
{
	t_player	*player;
	t_game		*game;

	player = &engine->player;
	game = &engine->game;
	if (
		check_lines(game) == 1 
		&& check_boarder(game) == 1
		&& check_p_e_c(&engine->symbols) == 1
		&& check_path(game, player->y, player->x) == 1
		)
		return (1);
	return (0);
}