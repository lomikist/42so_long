#include "../utils/get_next_line/get_next_line.h" 
#include <fcntl.h>

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
int check_path(char **map, int y, int x )
{
	//up
	if (map[y - 1][x] == 'E')
		return (1);
	else if (map[y + 1][x] == 'E')
		return (1);
	else if (map[y][x + 1] == 'E')
		return (1);

	if (map[y - 1][x] == '0')
		check_path(map, y - 1, x);
	else if (map[y][x + 1] == '0')
		check_path(map, y, x + 1);
	else if (map[y + 1][x] == '0')
	{
		map[y][x] = '3';
		check_path(map, y + 1, x);
	}
	else if (map[y][x - 1] == '0')
	{
		map[y][x] = '3';
		check_path(map, y, x - 1);
	}
	else
		return (0);
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
			printf("%d", check_path(map, i, finded_char - &map[i][0]));
		i++;
	}
	// check_lines(map);
	// check_border(map);
	close(fd);
	return (0);
}
