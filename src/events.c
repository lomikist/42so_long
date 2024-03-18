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
	else if (key == KEY_ESC)
		on_destroy_exit(engine);
	if (engine->player.points == engine->symbols.coin_c)
		engine->player.door_flag = 1;
	return (0);
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
	return (1);
}
