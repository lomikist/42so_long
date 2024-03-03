/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:58:57 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/28 21:59:01 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t len)
{
	unsigned long	i;
	unsigned char	*str;

	str = dest;
	i = 0;
	while (i < len)
	{
		i++;
		*str++ = 0;
	}
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
    ft_bzero(str , 5);
	puts(str);
}*/
