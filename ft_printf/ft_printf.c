/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:39:57 by arsargsy          #+#    #+#             */
/*   Updated: 2024/02/07 20:39:59 by arsargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dec_to_hex(ssize_t decimal, char *base, size_t divider)
{
	char	hexadecimal[100];
	int		i;
	int		count;
	int		remainder;

	i = 0;
	count = 0;
	remainder = 0;
	if (decimal == 0)
		count = ft_putchar('0');
	while (decimal != 0)
	{
		remainder = decimal % divider;
		hexadecimal[i] = base[remainder];
		decimal /= divider;
		++i;
	}
	while (i-- > 0)
	{
		write(1, &hexadecimal[i], 1);
		count++;
	}
	return (count);
}

int	prepear_for_hex(ssize_t number, char spc, int base_count)
{
	int	count;

	count = 0;
	if ((spc == 'd' || spc == 'i' || spc == 'u') && number < 0)
	{
		if (spc == 'u')
			number = (unsigned int)number;
		else
		{
			count += ft_putchar('-');
			number = -number;
		}
	}
	if (spc == 'p' && number == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else if (spc == 'p')
	{
		write(1, "0x", 2);
		count += 2;
	}
	count += dec_to_hex(number, "0123456789abcdef", base_count);
	return (count);
}

static char	*detect_next_char(char *str, va_list args, int *count)
{
	if (*str == 'd' || *str == 'i')
		*count = *count + prepear_for_hex(va_arg(args, int), 'd', 10);
	else if (*str == 'c')
		*count = *count + ft_putchar(va_arg(args, long long int));
	else if (*str == 'x')
		*count = *count + dec_to_hex(va_arg(args, unsigned int),
				"0123456789abcdef", 16);
	else if (*str == 'X')
		*count = *count + dec_to_hex(va_arg(args, unsigned int),
				"0123456789ABCDEF", 16);
	else if (*str == 'p')
		*count = *count + prepear_for_hex(va_arg(args, long), 'p', 16);
	else if (*str == 's')
		*count = *count + ft_putstr((char *)va_arg(args, long long int));
	else if (*str == 'u')
		*count = *count + prepear_for_hex(va_arg(args, unsigned int), 'u', 10);
	else if (*str == '%')
		*count = *count + ft_putchar('%');
	else
		return ("");
	return (str);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			str = detect_next_char((char *)(str + 1), args, &count);
		else
			count += ft_putchar(*str);
		str++;
	}
	return (count);
}
