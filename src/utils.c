/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:07:41 by arsargsy          #+#    #+#             */
/*   Updated: 2024/03/18 23:07:43 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "checker.h"

void	error_message(char *sms)
{
	ft_printf("%s\n", sms);
	exit(EXIT_FAILURE);
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
	ft_printf("You did %d moves\n", engine->player.move_count);
	error_message(sms);
}

int	on_destroy_exit(t_engine *engine)
{
	mlx_destroy_window(engine->mlx, engine->window);
	map_free(engine->game.m_h, engine->game.map);
	map_free(engine->game.m_h, engine->game.map_cp);
	ft_printf("You leftthe game and did %d moves\n", engine->player.move_count);
	exit(EXIT_SUCCESS);
}
