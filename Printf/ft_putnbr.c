/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:27:08 by tkartasl          #+#    #+#             */
/*   Updated: 2023/11/16 13:08:40 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(long int n)
{
	int		i;
	char	arr[10];
	int		count;

	count = 0;
	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		count = ft_write_fail_test(count, write(1, "-", 1));
		if (count < 0)
			return (-1);
		n = n * (-1);
	}
	while (n > 0)
	{
		arr[i++] = n % 10 + '0';
		n /= 10;
	}
	while (i > 0 && count >= 0)
		count = ft_write_fail_test(count, ft_putchar(arr[--i]));
	return (count);
}
