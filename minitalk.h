/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:54:27 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/29 19:58:51 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putnbr(int nb);
int	ft_put_unsigned(unsigned int n);
int	ft_put_hexa(unsigned int n, char format);
int	ft_put_ptr(void *ptr);

#endif