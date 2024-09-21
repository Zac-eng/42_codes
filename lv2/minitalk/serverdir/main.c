/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:38:24 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/16 17:41:12 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

volatile int	g_signal = 0;

static void	print_pid(void);
static void	signal_handler_one(int code);
static void	signal_handler_two(int code);
static void	print_signal_error(void);

int	main(void)
{
	int	digit;
	int	bin_holder[8];

	print_pid();
	while (1)
	{
		digit = 0;
		while (digit < 8)
		{
			if (signal(SIGUSR1, signal_handler_one) == SIG_ERR)
				print_signal_error();
			if (signal(SIGUSR2, signal_handler_two) == SIG_ERR)
				print_signal_error();
			pause();
			bin_holder[7 - digit] = g_signal;
			digit += 1;
		}
		generate_char(&bin_holder[0]);
	}
	return (0);
}

static void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
}

static void	print_signal_error(void)
{
	ft_printf("error occured when receiving signal\n");
	exit(1);
}

static void	signal_handler_one(int code)
{
	code += 1;
	g_signal = 0;
}

static void	signal_handler_two(int code)
{
	code += 1;
	g_signal = 1;
}
