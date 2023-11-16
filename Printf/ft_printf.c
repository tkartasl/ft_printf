/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:19:38 by tkartasl          #+#    #+#             */
/*   Updated: 2023/11/16 13:08:06 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(char *format, unsigned int hex)
{
	char	str[16];
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (hex == 0)
		return (write(1, "0", 1));
	while (hex != 0)
	{
		if (hex % 16 < 10)
			str[i] = hex % 16 + '0';
		else
		{
			if (*format == 'x')
				str[i] = hex % 16 + 'a' - 10;
			if (*format == 'X')
				str[i] = hex % 16 + 'A' - 10;
		}
		hex = hex / 16;
		i++;
	}
	while (i > 0 && count >= 0)
		count = ft_write_fail_test(count, ft_putchar(str[--i]));
	return (count);
}

int	ft_putptr(unsigned long hex)
{
	char	str[16];
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (hex == 0)
		return (write(1, "0x0", 3));
	count = ft_write_fail_test(count, write(1, "0x", 2));
	if (count < 0)
		return (-1);
	while (hex != 0)
	{
		if (hex % 16 < 10)
			str[i] = hex % 16 + '0';
		else
			str[i] = hex % 16 + 'a' - 10;
		hex = hex / 16;
		i++;
	}
	while (i > 0 && count >= 0)
		count = ft_write_fail_test(count, ft_putchar(str[--i]));
	return (count);
}

int	ft_print_format(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == '%')
		count = ft_write_fail_test(count, write(1, "%", 1));
	if (format == 'd' || format == 'i')
		count = ft_putnbr((long int)va_arg(args, int));
	if (format == 'u')
		count = ft_putnbr((unsigned int)va_arg(args, int));
	if (format == 's')
		count = ft_putstr(va_arg(args, char *));
	if (format == 'c')
		count = ft_putchar(va_arg(args, int));
	if (format == 'p')
		count = ft_putptr((unsigned long)va_arg(args, void *));
	if (format == 'x' || format == 'X')
		count = ft_puthex(&format, (unsigned int)va_arg(args, int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			count = ft_write_fail_test(count, ft_print_format(*format, args));
		}
		else
			count = ft_write_fail_test(count, write(1, format, 1));
		if (count < 0)
			return (count);
		format++;
	}
	va_end(args);
	return (count);
}
