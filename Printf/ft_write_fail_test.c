/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_fail_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:05:53 by tkartasl          #+#    #+#             */
/*   Updated: 2023/11/16 11:46:53 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_write_fail_test(int count, int i)
{
	if (count < 0 || i < 0)
		return (-1);
	else
		return (count + i);
}
