/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:31:26 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/29 17:53:05 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

int	ft_put_hexa(unsigned int n, char format)
{
	char	*base;
	int		count;

	count = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_put_hexa(n / 16, format);
	count += write(1, &base[n % 16], 1);
	return (count);
}
