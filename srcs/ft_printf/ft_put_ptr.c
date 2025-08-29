/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:31:18 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/29 17:53:09 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

static int	ft_putptr_aux(unsigned long n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_putptr_aux(n / 16);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int	ft_put_ptr(void *ptr)
{
	int				count;
	unsigned long	n;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	n = (unsigned long)ptr;
	count += write(1, "0x", 2);
	count += ft_putptr_aux(n);
	return (count);
}
