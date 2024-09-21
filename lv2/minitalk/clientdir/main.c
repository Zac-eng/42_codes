/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:39:07 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/16 17:09:46 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("the number of argument is invalid\n");
		return (0);
	}
	pid = read_pid(argv[1]);
	if (pid < 0)
	{
		ft_printf("pid input is invalid\n");
		return (0);
	}
	while (*argv[2] != '\0')
	{
		send_charactor(pid, *argv[2]);
		argv[2] += 1;
	}
	return (0);
}
