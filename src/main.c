#include "../utils/get_next_line/get_next_line.h" 
#include <fcntl.h>
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

char	**read_map(int fd)
{
	char	**result;
	char	*one_line;
	char	*file_content_in_one_line;
	int		i;

	i = 0;
	one_line = get_next_line(fd);
	while (one_line)
	{
		if (i == 0)
			file_content_in_one_line = ft_strdup((const char *)one_line);
		else
		{
			one_line = get_next_line(fd);
			if (one_line)
				file_content_in_one_line = ft_strjoin_gnl(file_content_in_one_line, one_line);
		}
		free(one_line);
		i++;
	}
	result = ft_split(file_content_in_one_line, '\n');
	free(file_content_in_one_line);
	return (result);
}

// int	check_border(const char **map)
// {

// }
int check_path(char **map, int y, int x, int from_dir)
{
	if (map[y][x] == 'E')
		return (1);

	if (from_dir == DOWN && map[y - 1][x] == '1' && map[y][x + 1] == '1' && map[y][x - 1] == '1')
		return 0;
	else if (from_dir == UP && map[y + 1][x] == '1' && map[y][x + 1] == '1' && map[y][x - 1] == '1')
		return 0;
	else if (from_dir == RIGHT && map[y][x - 1] == '1' && map[y + 1][x] == '1' && map[y - 1][x] == '1')
		return 0;
	else if (from_dir == LEFT && map[y][x + 1] == '1' && map[y + 1][x] == '1' && map[y - 1][x] == '1')
		return 0;

	if ((y - 1) > 0 && check_path(map, y - 1, x, DOWN) == 1 && from_dir == DOWN)
		return 1;
	else if ((y + 1) < 5 && check_path(map, y + 1, x, UP) == 1 && from_dir == UP)
		return 1;
	else if ((x + 1) < 12 && check_path(map, y, x + 1, LEFT) == 1 && from_dir == LEFT)
		return 1;
	else if ((x - 1) > 0 && check_path(map, y, x - 1, RIGHT) && from_dir == RIGHT)
		return 1;
	return 0;
}

int	check_lines(char **map)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	char	**map;
	char	*finded_char;
	int		fd;
	int		i;

	i = 0;
	fd = open("./maps/map.bar", O_RDONLY);
	map = read_map(fd);
	while (map[i])
	{
		finded_char = ft_strchr((const char*)map[i], 'P');
		if (finded_char)
			printf("%d", check_path(map, i, finded_char - &map[i][0], 0));
		i++;
	}
	// check_lines(map);
	// check_border(map);
	close(fd);
	return (0);
}
