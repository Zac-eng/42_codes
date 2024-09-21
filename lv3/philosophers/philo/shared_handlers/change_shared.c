/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_shared.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:55:00 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/08 22:19:58 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	switch_allalive(t_table *table)
{
	if (table == NULL)
		return ;
	if (pthread_mutex_lock(&table->alive_mutex) == 0)
	{
		if (table->all_alive == 1)
			table->all_alive = 0;
		pthread_mutex_unlock(&table->alive_mutex);
	}
}

int	update_last_eat(t_philo *philo)
{
	if (philo == NULL)
		return (-1);
	if (pthread_mutex_lock(&philo->philo_mutex) == 0)
	{
		if (get_time_ms(&philo->last_eat) == -1)
		{
			pthread_mutex_unlock(&philo->philo_mutex);
			return (-1);
		}
		if (pthread_mutex_unlock(&philo->philo_mutex) != 0)
			return (-1);
		return (0);
	}
	else
		return (-1);
}

int	increment_have_eaten(t_philo *philo)
{
	if (philo == NULL)
		return (-1);
	if (pthread_mutex_lock(&philo->philo_mutex) == 0)
	{
		philo->have_eaten++;
		if (pthread_mutex_unlock(&philo->philo_mutex) != 0)
			return (-1);
		return (0);
	}
	else
		return (-1);
}
