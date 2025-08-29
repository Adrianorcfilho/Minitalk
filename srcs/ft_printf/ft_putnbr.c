/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:11:37 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/29 17:53:14 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

int	ft_putnbr(int nb)
{
	long	long_nb;
	char	c;
	int		count;

	count = 0;
	long_nb = nb;
	if (long_nb < 0)
	{
		long_nb = -long_nb;
		count += write(1, "-", 1);
	}
	if (long_nb >= 10)
		count += ft_putnbr(long_nb / 10);
	c = (long_nb % 10) + 48;
	count += write(1, &c, 1);
	return (count);
}
