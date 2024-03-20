/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:40:08 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/28 21:45:51 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	foo(char *str, int i, unsigned int number, int sign)
{
	while (str[i] != '\0')
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			number = number * 10 + (str[i] - '0');
			i++;
		}
		else
			return (number * sign);
	}
	return (number * sign);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	number;
	int				sign;

	sign = 1;
	i = 0;
	number = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (foo((char *)str, i, number, sign));
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main()
// {
//     char k[] = "214748ffff3647          ";
//     // 2147483647, -2147483648
//     printf("%d\n", atoi((e + "+42lyon").c_str()));
//     printf("%d\n", ft_atoi((e + "+42lyon").c_str());
// }