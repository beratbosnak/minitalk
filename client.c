/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:42:41 by bbosnak           #+#    #+#             */
/*   Updated: 2023/08/03 03:42:42 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char c)
{
	int	slide;
	int	error;

	slide = 7;
	error = 0;
	while (slide >= 0)
	{
		if ((c >> slide & 1) == 0)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		slide--;
		usleep(200);
	}
	if (error == -1)
	{
		ft_putstr("Invalid PID !\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		i = -1;
		while (av[2][++i])
			send_signal(pid, av[2][i]);
	}
	else
		ft_putstr("Invalid arguments !\n");
}
