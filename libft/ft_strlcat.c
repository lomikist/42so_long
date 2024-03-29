/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:03:44 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/28 23:04:04 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		dest_len;
	size_t		total_len;
	const char	*s;

	s = src;
	dest_len = 0;
	if ((!dest || !src) && !n)
		return (0);
	while (*(dest + dest_len) && dest_len < n)
		dest_len++;
	if (dest_len < n)
		total_len = dest_len + ft_strlen(s);
	else
		return (n + ft_strlen(s));
	while (*s && (dest_len + 1) < n)
	{
		*(dest + dest_len) = *s++;
		dest_len++;
	}
	*(dest + dest_len) = '\0';
	return (total_len);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char src[40] = "lalsdfsdfsdfa";

	char dest[80] = "catscats";
	char dest2[80] = "catscats";
	
	int result = strlcat(dest, src, 3);
	int result2 = ft_strlcat(dest2, src, 3);	

	printf("his --%d-----%s----\n", result,dest); 
	printf("my  --%d-----%s----\n", result2, dest2);
}*/
