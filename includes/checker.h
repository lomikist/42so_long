/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:52:58 by arsargsy          #+#    #+#             */
/*   Updated: 2024/03/21 22:53:01 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"
# include "../includes/get_next_line.h" 
# include "../libft/libft.h" 
#include "../includes/get_next_line.h" 

# define BLOCK_SIZE 80

typedef struct s_symbols
{
	int		player_c;
	int		exit_c;
	int		enemy_c;
	int		coin_c;
}	t_symbols;

typedef struct s_imgs
{
	void	*p_1;
	void	*p_2;
	void	*grass;
	void	*coin;
	void	*coin2;
	void	*enemy1;
	void	*enemy2;
	void	*wall;
	void	*door_1;
	void	*door_2;
	void	*bg;
}	t_imgs;

typedef struct s_player
{
	int	x;
	int	y;
	int	points;
	int	img_flag;
	int	door_flag;
	int	move_count;
}	t_player;

typedef struct s_game
{
	char	**map;
	char	**map_cp;
	int		m_h;
	int		m_w;
}	t_game;

typedef struct s_engine
{
	t_player	player;
	t_game		game;
	t_symbols	symbols;
	t_imgs		imgs;
	int			frame_count;
	void		*mlx;
	void		*window;
}	t_engine;

void	error_message(char *sms);
int		check(t_engine *engine);
void	move_vertical(t_engine *engine, int key);
void	move_horizontal(t_engine *engine, int key);
int		on_destroy_exit(t_engine *engine);
int		on_key_hook_event(int key, t_engine *engine);
void	close_window_free_and_exit(t_engine *engine, char *sms);
void	draw_points(t_engine *engine);
int		draw_game(t_engine *engine);
void	draw_block(t_engine *engine, char symbol, int i, int j);
int		check_p_e_c(t_engine *engine);
int		check_boarder(t_engine *engine);
int		check_lines(t_engine *engine);
int		check_dead_case(t_engine *engine, int y, int x);
int		check_path(t_engine *engine, int y, int x);
void	args_valid(int argc, char **argv);
char	**read_map(int fd);

#endif