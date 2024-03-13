/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:14:19 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/28 22:14:20 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "checker.h"
#include <stdlib.h>

static int	int_size(long long int n)
{
	int	len;

	len = 0;
	if (n < 1)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*new_str(size_t n)
{
	char	*str;

	str = (char *)malloc(n + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	m;
	int				sign;
	int				len;
	char			*str;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = int_size(n);
	str = new_str(len);
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	if (n < 0)
		m = -n;
	else
		m = n;
	while (len--)
	{
		*(str + len) = 48 + m % 10;
		m /= 10;
	}
	if (sign)
		*(str) = 45;
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	char *result = ft_itoa(-140225);

// 	puts(result);
// 	free(result);
// 	return (0);
// }
