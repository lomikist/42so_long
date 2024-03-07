#include "../utils/get_next_line/get_next_line.h" 
#include <fcntl.h>
#include "checker.h"

char	**read_map(int fd)
{
	char	**result;
	char	*one_line;
	char	*file_summary;
	int		i;

	i = 0;
	one_line = get_next_line(fd);
	while (one_line)
	{
		if (i == 0)
			file_summary = ft_strdup((const char *)one_line);
		else
		{
			one_line = get_next_line(fd);
			if (one_line)
				file_summary = ft_strjoin_gnl(file_summary, one_line);
		}
		free(one_line);
		i++;
	}
	result = ft_split(file_summary, '\n');
	free(file_summary);
	return (result);
}


int	main(void)
{
	int				fd;
	struct s_point	point;
	struct s_game	game;

	fd = open("./maps/map.bar", O_RDONLY);
	game.map = read_map(fd);
	close(fd);
	fd = open("./maps/map.bar", O_RDONLY);
	game.map_cp = read_map(fd);
	close(fd);
	check(&game, &point);
	return (0);
}
