#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include <fcntl.h>

char **read_map(int fd);

int main()
{
	char	**map;
	int		fd;
	
	fd = open("../maps/map.bar", O_RDONLY);
	map = read_map(fd);
	close(fd);
}

char **read_map(int fd)
{
	char	**result;
	char	*one_line;
	char	*file_content_in_one_line;
	int		i;

	i = 0;
	while (one_line != NULL)
	{
		one_line = get_next_line(fd);
		if(i == 0)
			file_content_in_one_line = ft_strdup((const char *)one_line);
		else if (one_line != NULL)
			file_content_in_one_line = ft_strjoin_gnl(file_content_in_one_line, one_line);
		free(one_line);
		i++;
	}
	result = ft_split(file_content_in_one_line, '\n');
	free(file_content_in_one_line);
	return (result);
}
