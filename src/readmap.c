/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:56:41 by arsargsy          #+#    #+#             */
/*   Updated: 2024/03/23 22:56:43 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	contains_consecutive_newlines(char *str)
{
	if (!str)
		error_message("Problem with map with.");
	if (str[0] == '\n')
		error_message("Problem with map with.");
	while (*str)
	{
		if (*str == '\n')
		{
			if (*(str + 1) == '\n')
				error_message("Problem with map with.");
		}
		str++;
	}
	str--;
	if (*str == '\n')
		error_message("Problem with map with.");
}

char	**read_map(int fd)
{
	char	**result;
	char	*one_line;
	char	*file_summary;
	int		i;

	i = 0;
	file_summary = NULL;
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
	contains_consecutive_newlines(file_summary);
	result = ft_split(file_summary, '\n');
	free(file_summary);
	return (result);
}
