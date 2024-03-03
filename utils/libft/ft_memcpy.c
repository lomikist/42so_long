/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:40:58 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/28 22:41:00 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*str;

	str = dst;
	i = 0;
	if (n == 0)
		return (dst);
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		str[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
