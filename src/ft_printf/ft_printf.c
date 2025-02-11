/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajodar-c <ajodar-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:15:09 by ajodar-c          #+#    #+#             */
/*   Updated: 2024/12/17 11:59:25 by ajodar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numbers(va_list arguments, int flag_unsigned)
{
	long	num;
	int		count;

	if (flag_unsigned)
		num = va_arg(arguments, unsigned int);
	else
		num = va_arg(arguments, int);
	count = ft_putnbrs_print(num, flag_unsigned);
	return (count);
}

static int	ft_hex(unsigned int num, char *format)
{
	char	toprint[8];
	int		count;
	int		i;

	i = 0;
	if (num == 0)
	{
		ft_putchar_print('0');
		return (1);
	}
	while (num > 0)
	{
		toprint[i] = format[num % 16];
		num = num / 16;
		i++;
	}
	count = i;
	while (--i >= 0)
		ft_putchar_print(toprint[i]);
	return (count);
}

static int	ft_phex(unsigned long ptr, char *format)
{
	char	toprint[16];
	int		count;
	int		i;

	i = 0;
	if (!ptr)
	{
		ft_putstr_print("(nil)");
		return (5);
	}
	ft_putstr_print("0x");
	if (ptr == 0)
	{
		ft_putchar_print('0');
		return (1);
	}
	while (ptr > 0)
	{
		toprint[i++] = format[ptr % 16];
		ptr = ptr / 16;
	}
	count = i + 2;
	while (--i >= 0)
		ft_putchar_print(toprint[i]);
	return (count);
}

static int	ft_format(const char *format, va_list arguments)
{
	int	cnt;

	cnt = 0;
	if (*format == '%')
		cnt = ft_putchar_print('%');
	if (*format == 'c')
		cnt = ft_putchar_print((char)va_arg(arguments, int));
	if (*format == 's')
		cnt = ft_putstr_print(va_arg(arguments, char *));
	if (*format == 'd' || *format == 'i')
		cnt = ft_numbers(arguments, 0);
	if (*format == 'u')
		cnt = ft_numbers(arguments, 1);
	if (*format == 'x')
		cnt = ft_hex(va_arg(arguments, unsigned int), "0123456789abcdef");
	if (*format == 'X')
		cnt = ft_hex(va_arg(arguments, unsigned int), "0123456789ABCDEF");
	if (*format == 'p')
		cnt = ft_phex(va_arg(arguments, unsigned long), "0123456789abcdef");
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arguments;

	va_start(arguments, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				count = -1;
				break ;
			}
			count += ft_format(format++, arguments);
		}
		else
		{
			ft_putchar_print(*format++);
			count++;
		}
	}
	va_end(arguments);
	return (count);
}
