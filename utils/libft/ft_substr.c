/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:11:29 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/28 23:11:31 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	str_len;
	char			*substr;

	if (!s)
		return (0);
	str_len = ft_strlen(s);
	if (start >= str_len)
		len = 0;
	if (len > str_len - start)
		len = str_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (0);
	i = 0;
	while (i < len && s[start])
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// int main()
// {
//     char * s1 = "12344566789";
//     char * s2;

//     s2 = ft_substr(s1, 4, 5);
//     printf("%s",s2);
// }
