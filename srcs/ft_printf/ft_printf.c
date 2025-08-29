/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:56:28 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/29 17:52:54 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

int	ft_printf_find(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (type == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		count += ft_put_unsigned(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_put_hexa(va_arg(args, unsigned int), type);
	else if (type == 'p')
		count += ft_put_ptr(va_arg(args, void *));
	else if (type == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (!format || write(1, NULL, 0) == -1)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i] != '\0' && ++i)
			count += ft_printf_find(format[i++], args);
		else if (format[i] == '%' && format[i + 1] == '\0')
			return (count);
		else
			count += ft_putchar(format[i++]);
	}
	va_end(args);
	return (count);
}
