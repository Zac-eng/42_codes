/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:55:07 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/08 22:21:51 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_action(long int timestamp, int philo_id, t_table *table, char action)
{
	if (table == NULL)
		return (-1);
	if (pthread_mutex_lock(&table->alive_mutex) == 0)
	{
		if (table->all_alive == 1)
		{
			if (action == 'f')
				printf("%ld %d has taken a fork\n", timestamp, philo_id);
			else if (action == 'e')
				printf("%ld %d is eating\n", timestamp, philo_id);
			else if (action == 's')
				printf("%ld %d is sleeping\n", timestamp, philo_id);
			else if (action == 't')
				printf("%ld %d is thinking\n", timestamp, philo_id);
			if (pthread_mutex_unlock(&table->alive_mutex) != 0)
				return (-1);
			return (0);
		}
		if (pthread_mutex_unlock(&table->alive_mutex) != 0)
			return (-1);
		return (1);
	}
	return (-1);
}

int	print_died(long int timestamp, int philo_id, t_table *table)
{
	if (table == NULL)
		return (-1);
	if (pthread_mutex_lock(&table->alive_mutex) == 0)
	{
		if (table->all_alive == 1)
		{
			printf("%ld %d died\n", timestamp, philo_id);
			table->all_alive = 0;
			if (pthread_mutex_unlock(&table->alive_mutex) != 0)
				return (-1);
			return (0);
		}
		if (pthread_mutex_unlock(&table->alive_mutex) != 0)
			return (-1);
		return (1);
	}
	return (-1);
}
