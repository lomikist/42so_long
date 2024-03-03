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
int	main(void)
{
	char	**map;
	int		fd;

	fd = open("./maps/map.bar", O_RDONLY);
	map = read_map(fd);
	close(fd);
}
