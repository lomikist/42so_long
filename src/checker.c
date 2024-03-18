/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:06:06 by arsargsy          #+#    #+#             */
/*   Updated: 2024/03/18 23:06:08 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_dead_case(t_engine *engine, int y, int x)
{
	t_game	*game;

	game = &engine->game;
	if ((game->map_cp[y + 1][x] == '1' || game->map_cp[y + 1][x] == '2')
		&& (game->map_cp[y - 1][x] == '1' || game->map_cp[y - 1][x] == '2')
		&& (game->map_cp[y][x + 1] == '1' || game->map_cp[y][x + 1] == '2')
		&& (game->map_cp[y][x - 1] == '1' || game->map_cp[y][x - 1] == '2'))
		return (1);
	else
		return (0);
}

int	check_path(t_engine *engine, int y, int x)
{
	t_player	*player;
	t_game		*game;

	player = &engine->player;
	game = &engine->game;
	if (game->map_cp[y][x] == 'E')
		return (1);
	if (game->map_cp[y][x] == '1')
		return (0);
	if (game->map_cp[y][x] == '2')
		return (0);
	game->map_cp[y][x] = '2';
	if (check_dead_case(engine, y, x))
		game->map_cp[y][x] = '1';
	if (check_path(engine, y - 1, x) || check_path(engine, y, x - 1)
		|| check_path(engine, y, x + 1) || check_path(engine, y + 1, x))
		return (1);
	else
		return (0);
}

int	check_lines(t_engine *engine)
{
	t_game	*game;
	int		i;
	size_t	len;

	game = &engine->game;
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

int	check_boarder(t_engine *engine)
{
	t_game		*game;
	int			i;

	i = 0;
	game = &engine->game;
	while (i < game->m_w)
	{
		if (game->map[0][i] != '1'
			|| game->map[game->m_h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->m_h)
	{
		if (game->map[i][0] != '1'
			|| game->map[i][game->m_w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_p_e_c(t_engine *engine)
{
	t_symbols	*symbols;

	symbols = &engine->symbols;
	if (symbols->exit_c == 1 && symbols->player_c == 1 && symbols->coin_c > 1)
		return (1);
	return (0);
}
