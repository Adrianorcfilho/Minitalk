/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:51:13 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/20 21:40:51 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	my_msg(char c)
{
	
}

int	main(int ac, char *av[])
{
	int pid;
	// int i;
	// char *msg;
	
	pid = atoi(av[1]);
	
	kill(pid, SIGUSR1);
	usleep(1500);
	kill(pid, SIGUSR2);
	(void)ac;
	// while (msg[i])
	// {
	// 	i++;
	// }
}