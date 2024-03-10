#ifndef CHECKER_H
# define CHECKER_H

struct s_symbols
{
	int		player_c;
	int		exit_c;
	int		enemy_c;
	int		coin_c;
}
typedef	t_symbols;

struct s_player
{
	int	x;
	int	y;
}
typedef	t_player;

struct s_game
{
	char	**map;
	char	**map_cp;
	int		m_h;
	int		m_w;
}
typedef	t_game;

struct s_engine
{
	t_player	player;
	t_game		game;
	t_symbols	symbols;
}typedef t_engine;

int	check(t_engine*);

#endif