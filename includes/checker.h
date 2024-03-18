#include "mlx.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include "../includes/get_next_line.h" 
#define BLOCK_SIZE 80

#ifndef CHECKER_H
# define CHECKER_H

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
	void	*enemy;
	void	*wall;
	void	*door_1;
	void	*door_2;
	void	*bg;
}	t_imgs;

typedef struct s_player
{
	int	x;
	int	y;
	int points;
	int img_flag;
	int door_flag;
	int move_count;
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
	void		*mlx;
	void		*window;
}	t_engine;

void	error_message(char *sms);
int		check(t_engine *engine);
void	move_vertical(t_engine *engine, int key);
void	move_horizontal(t_engine *engine, int key);
int		on_destroy_exit(t_engine *engine);
int		on_key_hook_event(int key, t_engine *engine);
char	*ft_itoa(int n);
char	*ft_strjoin_gnl(char *s1, const char *s2);
void	close_window_free_and_exit(t_engine *engine, char *sms);
void	draw_points(t_engine *engine);
int		draw_game(t_engine *engine);
void	draw_block(t_engine *engine, char symbol, int i, int j);
int		check_p_e_c(t_engine *engine);
int		check_boarder(t_engine *engine);
int		check_lines(t_engine *engine);
int		check_dead_case(t_engine *engine, int y, int x);
int		check_path(t_engine *engine, int y, int x);

#endif