/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porg <porg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:21:48 by porg              #+#    #+#             */
/*   Updated: 2022/03/01 17:11:38 by porg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static int	i = 0;
	static char	c = 0;

	c |= (sig == SIGUSR1); 
	if (++i == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		i = 0;
	}
	else
		c <<= 1;
}

int	main()
{
	int	pid;

	pid = (int)getpid();
	ft_printf("PID: %d\n", pid);
	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
		ft_printf("error1");
	if (signal(SIGUSR2, sig_handler) == SIG_ERR)
		ft_printf("error2");
	while (1)
		sleep(0);
	return (0);
}
