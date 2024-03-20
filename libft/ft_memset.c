/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:44:55 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/28 22:44:58 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*str;

	str = dest;
	i = 0;
	while (i < len)
	{
		i++;
		*str++ = c;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char str[50];

	strcpy(str, "This is string.h library function");
	puts(str);

	// memset(str, 'g', 5);
	puts(ft_memset(str, 'g', 5));

}*/
