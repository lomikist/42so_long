/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:04:49 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/28 23:04:51 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (len(src));
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len(src));
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char a[] = "asvsv";
	char b[5];
	char l[5];

	int t = ft_strlcpy(b, a, 4);
	int c = strlcpy(l, a, 4);
	printf("my %d \n",t);			
	printf("his %d \n",c);			
	printf("his %s \n",b);
	printf("my %s", l);			
}*/
