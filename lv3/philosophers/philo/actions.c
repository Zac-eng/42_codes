/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:25:47 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/08 22:29:13 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo *philo, t_table *table)
{
	long int	c_time;
	long int	timestamp;

	if (philo == NULL || table == NULL)
		return (0);
	if (lock_forks(philo) != 0)
		return (-1);
	if (get_time_ms(&c_time) != 0)
		return (unlock_forks(philo) * 0 - 1);
	timestamp = create_timestamp(c_time, table);
	if (timestamp < 0)
		return (unlock_forks(philo) * 0 - 1);
	if (print_action(timestamp, philo->philo_id, table, 'f') != 0)
		return (unlock_forks(philo) * 0 - 1);
	return (0);
}

int	start_eating(t_philo *philo, t_table *table)
{
	long int	c_time;
	long int	timestamp;

	if (philo == NULL || table == NULL)
		return (0);
	if (get_time_ms(&c_time) != 0)
		return (unlock_forks(philo) * 0 - 1);
	timestamp = create_timestamp(c_time, table);
	if (timestamp < 0)
		return (unlock_forks(philo) * 0 - 1);
	if (print_action(timestamp, philo->philo_id, table, 'e') != 0)
		return (unlock_forks(philo) * 0 - 1);
	if (update_last_eat(philo) < 0)
		return (unlock_forks(philo) * 0 - 1);
	if (wait_action(get_time(table, 'e'), table) != 0)
		return (unlock_forks(philo) * 0 - 1);
	if (increment_have_eaten(philo) < 0)
		return (unlock_forks(philo) * 0 - 1);
	if (unlock_forks(philo) != 0)
		return (-1);
	return (0);
}

int	start_sleeping(t_philo *philo, t_table *table)
{
	long int	c_time;
	long int	timestamp;

	if (philo == NULL || table == NULL)
		return (0);
	if (get_time_ms(&c_time) != 0)
		return (-1);
	timestamp = create_timestamp(c_time, table);
	if (timestamp < 0)
		return (-1);
	if (print_action(timestamp, philo->philo_id, table, 's') != 0)
		return (-1);
	if (wait_action(get_time(table, 's'), table) != 0)
		return (-1);
	return (0);
}

int	start_thinking(t_philo *philo, t_table *table)
{
	long int	c_time;
	long int	timestamp;

	if (philo == NULL || table == NULL)
		return (0);
	if (get_time_ms(&c_time) != 0)
		return (-1);
	timestamp = create_timestamp(c_time, table);
	if (timestamp < 0)
		return (-1);
	if (print_action(timestamp, philo->philo_id, table, 't') != 0)
		return (-1);
	return (0);
}

int	died(int philo_id, t_table *table)
{
	long int	c_time;
	long int	timestamp;

	if (table == NULL)
		return (-1);
	if (get_time_ms(&c_time) != 0)
		return (-1);
	timestamp = create_timestamp(c_time, table);
	if (timestamp < 0)
		return (-1);
	if (print_died(timestamp, philo_id, table) != 0)
		return (-1);
	return (0);
}
