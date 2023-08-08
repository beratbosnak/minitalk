/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:42:34 by bbosnak           #+#    #+#             */
/*   Updated: 2023/08/03 03:42:35 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static char	byte = 0;
	static int	slide = 7;

	if (sig == SIGUSR2)
		byte += 1 << slide;
	if (slide == 0)
	{
		ft_putchar(byte);
		byte = 0;
		slide = 8;
	}
	slide--;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}
