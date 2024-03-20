/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:09:47 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/30 20:03:57 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	s1_len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	s1_len = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		++start;
	end = s1_len - 1;
	while (ft_strchr(set, s1[end]) && end >= start)
		--end;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
/*#include <stdio.h>
int main (){
	char *a;
	a = ft_strtrim("     "," ");
    // printf("dds%sdss",ft_strtrim("          ", " "));
	puts(a);
	free(a);
	puts("dsfs");
}
*/
// #include <stdio.h>
// int main(){
//   // const char *str1 = "dfdfdfdfdffffffhellffffffffffdddddddddd";
//     // char *s1 = "\t   \t \t\n\n\n\n\n \n\t\n \n  \n \n \n\t";
// 	// char s2[] = "          ";
// 	char *s = ft_strtrim("abcdba", "acb");
// 	puts(s);
// 	// char *strim;
//     // // char *s2 = "Hello \t  Please\n Trim me !";
// 	// strim = ft_strtrim(s2, " ");

//     // s1 = ft_strtrim(s1," \t\n");
//     // // str2 = ft_strtrim(str2," \n\t);
//     // puts(s1);
// 	// puts(strim);
// }
