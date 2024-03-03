/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:48:02 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/28 22:48:05 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	comb[11];

	i = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
		{
			n = n * -1;
			write(fd, "-", 1);
		}
		while (n > 0)
		{
			comb[i] = (n % 10) + 48;
			n = n / 10;
			i++;
		}
		while (i-- > 0)
			write(fd, &comb[i], 1);
	}
}

// #include <stdio.h>
// #include <unistd.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd = open("test.txt", O_RDWR);

// 	ft_putnbr_fd(4832323, fd);
// 	close(fd);
// }
