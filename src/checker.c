#include "checker.h"
#include <stddef.h>
#include "../utils/get_next_line/get_next_line.h" 

int	check_dead_case(struct s_game *game, int y, int x)
{
	if ((game->map[y + 1][x] == '1' || game->map[y + 1][x] == '2')
		&& (game->map[y - 1][x] == '1' || game->map[y - 1][x] == '2')
		&& (game->map[y][x + 1] == '1' || game->map[y][x + 1] == '2')
		&& (game->map[y][x - 1] == '1' || game->map[y][x - 1] == '2'))
		return (1);
	else
		return (0);
}

int	check_path(struct s_game *game, int y, int x)
{
	if (game->map[y][x] == 'E')
		return (1);
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == '2')
		return (0);
	game->map[y][x] = '2';
	if (check_dead_case(game, y, x))
		game->map[y][x] = '1';
	if (check_path(game, y - 1, x) || check_path(game, y, x - 1)
		|| check_path(game, y, x + 1) || check_path(game, y + 1, x))
		return (1);
	else
		return (0);
}

int	check_lines(struct s_game *game)
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

int	check_player(struct s_game *game, struct s_point *point)
{
	char			*finded_char;
	int				i;

	i = 0;
	while (game->map[i])
	{
		finded_char = ft_strchr((const char *)game->map[i], 'P');
		if (finded_char)
		{
			point->x = finded_char - &game->map[i][0];
			point->y = i;
			point->from_dir = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

int check_boarder(struct s_game *game)
{
	
	return game->m_h;
};

int	check(struct s_game *game, struct s_point *point)
{
	check_lines(game);
	check_boarder(game);
	check_player(game, point);
	printf("%d",check_path(game, point->y, point->x));
	return 0;
}