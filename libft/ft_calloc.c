/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:08:52 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/28 22:09:00 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	if (count && size && count > (4294967295 / size))
		return (0);
	p = malloc(count * size);
	if (!p)
	{
		free(p);
		return (0);
	}
	ft_bzero(p, count * size);
	return (p);
}

// #include <stdio.h>
// int main()
// {
//     char * str = ft_calloc(4, 4);
//     printf("%s", str);
// }
