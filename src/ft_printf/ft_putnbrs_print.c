/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:08:49 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/11/07 15:17:46 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrs_print(long n, int flag_unsigned)
{
	int		count;

	count = 0;
	if (flag_unsigned == 1 && n < 0)
		n = -n;
	else if (flag_unsigned == 0 && n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbrs_print(n / 10, flag_unsigned);
	ft_putchar_print((n % 10) + '0');
	return (count + 1);
}
