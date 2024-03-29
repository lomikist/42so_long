/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:12:05 by arsargsy          #+#    #+#             */
/*   Updated: 2024/01/28 23:12:07 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
#include <unistd.h>

int main()
{
	char a[] = "absdfFzzzzSDKLJ^*&%$sf";

	ft_strlowcase(a);
	write(1,a,23);
}*/
