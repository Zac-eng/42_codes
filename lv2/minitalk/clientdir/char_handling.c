/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:22:59 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/16 17:41:27 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	siguser_handler(int pid, int bin);

int	send_charactor(int pid, unsigned char charactor)
{
	int	result;
	int	digit;

	digit = 0;
	result = 1;
	while (digit < 8)
	{
		result = siguser_handler(pid, charactor % 2);
		if (result == -1)
		{
			ft_printf("error occured when sending signal\n");
			exit(1);
		}
		charactor /= 2;
		digit += 1;
		usleep(100);
	}
	return (0);
}

int	siguser_handler(int pid, int bin)
{
	if (bin == 0)
		return (kill(pid, SIGUSR1));
	else if (bin == 1)
		return (kill(pid, SIGUSR2));
	else
	{
		ft_printf("signal should be binary\n");
		exit(1);
	}
	return (0);
}
