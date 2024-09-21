/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_pid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:08:50 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/16 17:51:53 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	check_overflow(int current_pid, char next_int);

int	read_pid(char *pid_string)
{
	int	pid;

	pid = 0;
	while (*pid_string != '\0')
	{
		if ('0' <= *pid_string && *pid_string <= '9')
		{
			if (check_overflow(pid, *pid_string) == 1)
				return (-1);
			pid = pid * 10 + (*pid_string - '0');
			pid_string += 1;
		}
		else
			return (-1);
	}
	return (pid);
}

static int	check_overflow(int current_pid, char next_int)
{
	int	next_digit;

	next_digit = next_int - '0';
	if (current_pid < INT_MAX / 10)
		return (0);
	else if (current_pid > INT_MAX / 10)
		return (1);
	else
	{
		if (next_digit > INT_MAX % 10)
			return (1);
		else
			return (0);
	}
}
