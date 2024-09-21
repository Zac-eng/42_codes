/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:18:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/08 22:22:10 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_action(long int wait_time_ms, t_table *table)
{
	long int	action_start;
	long int	time;

	if (table == NULL)
		return (-1);
	if (get_time_ms(&action_start) < 0)
		return (-1);
	if (get_time_ms(&time) < 0)
		return (-1);
	while (time + 20 < action_start + wait_time_ms)
	{
		if (get_allalive(table) == 1)
			usleep(10000);
		else
			return (1);
		if (get_time_ms(&time) < 0)
			return (-1);
	}
	while (time < action_start + wait_time_ms && get_allalive(table) == 1)
	{
		if (get_time_ms(&time) < 0)
			return (-1);
	}
	return (0);
}
