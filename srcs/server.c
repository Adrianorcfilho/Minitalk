/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:51:19 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/20 20:23:40 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	sighandler(int n)
{
	if (n == SIGUSR1)
	{
		fprintf(stderr, "DEU ZERO\n");
	}
	else if (n == SIGUSR2)
	{
		fprintf(stderr, "DEU Um, la ele\n");
	}
}

int	main(void)
{
	int pid;

	pid = getpid();
	fprintf(stderr, "Server PID: %d\n", pid);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
		pause();
}