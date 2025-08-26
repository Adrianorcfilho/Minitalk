/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:51:19 by adrocha-          #+#    #+#             */
/*   Updated: 2025/08/26 20:50:09 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp_s;
	size_t			i;

	i = 0;
	temp_s = (unsigned char *)s;
	while (i < n)
	{
		temp_s[i] = 0;
		i++;
	}
}

int	binary_change(int bin, char *str)
{
	static unsigned char	c;
	static int				bit;
	static int				index;

	c |= (bin << bit);
	if (bit == 7)
	{
		str[index++] = c;
		if (c == 0)
		{
			printf("%s\n", str);
			index = 0;
			free(str);
		}
		bit = 0;
		c = 0;
		if (index == 0)
			return (1);
	}
	else
		bit++;
	return (0);
}

void	sighandler(int signum, siginfo_t *info)
{
	static char		*str;
	static unsigned int	len;
	static int	i;
	static int	m;

	if (i < 32)
		len |= (signum << i++);
	else
	{
		if (m++ == 0)
		{
			str = malloc(len + 1);
			if (!str)
				exit(0);
		}
		if (binary_change(signum == SIGUSR2, str))
		{
			kill(info->si_pid, SIGUSR2);
			m = 0;
			len = 0;
			i = 0;
		}
		else
			kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	int pid;
	struct sigaction	action;

	pid = getpid();
	printf("Server PID: %d\n", pid);
	ft_bzero(&action, sizeof(action));
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = (void *)sighandler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
