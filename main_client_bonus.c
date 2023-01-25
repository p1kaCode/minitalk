/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorel <lmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:08:12 by lmorel            #+#    #+#             */
/*   Updated: 2023/01/25 15:32:38 by lmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	catch_back(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("CHAR has been recieved !\n");
}

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
	i = 0;
	if (!av[2])
		return (ERROR);
	while (av[2][i] != '\0')
	{
		signal(SIGUSR1, catch_back);
		signal(SIGUSR2, catch_back);
		send_char(ft_atoi(av[1]), av[2][i]);
		i++;
	}
	send_char(ft_atoi(av[1]), '\n');
	return (SUCCESS);
}
