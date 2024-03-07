#ifndef CHECKER_H
# define CHECKER_H

struct	s_point
{
	int	x;
	int	y;
	int	from_dir;
};

struct	s_game
{
	char	**map;
	char	**map_cp;
	int		m_h;
	int		m_v;
};

int	check(struct s_game *game, struct s_point *point);

#endif