/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:39:10 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/29 17:53:11 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

int	ft_put_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_put_unsigned(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
