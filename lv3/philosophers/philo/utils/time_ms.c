/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:47:44 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/08 22:18:47 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_ms(long int *time)
{
	t_time	current_time;

	if (time == NULL)
		return (-1);
	if (gettimeofday(&current_time, NULL) != 0)
		return (-1);
	*time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (0);
}

long int	create_timestamp(long int c_time, t_table *table)
{
	long int	start_time;

	if (table == NULL)
		return (-1);
	start_time = get_start_time(table);
	if (start_time < 0)
		return (-1);
	return (c_time - start_time);
}
