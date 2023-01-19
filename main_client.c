/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorel <lmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:08:12 by lmorel            #+#    #+#             */
/*   Updated: 2023/01/19 19:39:18 by lmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != '\0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3 || ft_atoi(av[1]) == 0)
	{
		if (ac > 3)
			ft_putstr_fd("ERROR : Too much parameters !\n", 2);
		else if (ac < 3)
			ft_putstr_fd("ERROR : Too few parameters !\n", 2);
		else if (ft_atoi(av[1]) <= 0)
			ft_putstr_fd("ERROR : Invalid PID\n", 2);
		return (ERROR);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	if (!av[2])
		return (ERROR);
	while (av[2][i] != '\0')
	{
		send_char(pid, av[2][i]);
		i++;
	}
	send_char(pid, '\n');
	return (SUCCESS);
}
