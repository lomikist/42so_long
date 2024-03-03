/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:08:38 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/28 23:08:40 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;

	str = (char *)s;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return (&str[len]);
		len--;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	char *c = "fsdfsdfsd sdafsdf sdf sdf sdf s dfdfdfdf     f";
// 	c = ft_strrchr(c, 'a');
// 	puts(c);
// }
