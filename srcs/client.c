/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:51:13 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/26 20:50:20 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void ft_strlen(char *s, int pid)
{
	int	bit;
	int i;

	i = 0;
	while (s[i])
		i++;
	bit = 0;
	while (bit < 32)
	{
		if ((i >> bit++) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
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
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1500);
	}
}
void handler(int signum)
{
	if (signum == SIGUSR2)
	{
		printf("Mensagem recebida\n");
		exit(0);
	}	
}

int	main(int ac, char *av[])
{
	int pid;
	int i;
	
	if (ac != 3)
	{
		write(2, "Expect: .client <PID> <message>\n", 32);
		return (1);
	}
	pid = atoi(av[1]);
	i = 0;
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	ft_strlen(av[2], pid);
	while (1)
	{
		my_msg(pid, av[2][i]);
		if (!av[2][i])
			break;
		i++;
	}
	pause();
}
