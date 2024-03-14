#include "mlx.h"
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
	void        *mlx;
	void        *window;
	t_imgs		imgs;
}	t_engine;

int	check(t_engine *);

#endif