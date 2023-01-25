/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_serv_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorel <lmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:05:09 by lmorel            #+#    #+#             */
/*   Updated: 2023/01/25 15:22:36 by lmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	c;

	(void)s;
	if (signal == SIGUSR1)
		c += (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	act;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("ERROR : Server don't need arguments to start.", 2);
		return (ERROR);
	}
	ft_printf("Starting ... Bonus version\n");
	ft_printf("PID : %d\n", getpid());
	act.sa_sigaction = signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (SUCCESS);
}
