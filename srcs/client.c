/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:51:13 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/29 19:54:33 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	sign;

	sign = 1;
	number = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * sign);
}

void	ft_strlen(char *s, int pid)
{
	int	bit;
	int	i;

	i = 0;
	while (s[i])
		i++;
	bit = 0;
	while (bit < 32)
	{
		if ((i >> bit++) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(0);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(0);
		}
		usleep(1500);
	}
}

void	my_msg(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit++) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(0);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(0);
		}
		usleep(1500);
	}
}
void	handler(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_printf("Mensagem recebida\n");
		exit(0);
	}
}

int	main(int ac, char *av[])
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		write(2, "Expect: .client <PID> <message>\n", 32);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		exit(1);
	i = 0;
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	ft_strlen(av[2], pid);
	while (1)
	{
		my_msg(pid, av[2][i]);
		if (!av[2][i])
			break ;
		i++;
	}
	pause();
}
