/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shared.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:20:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/08 22:21:12 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_allalive(t_table *table)
{
	int	all_alive;

	if (table == NULL)
		return (-1);
	if (pthread_mutex_lock(&table->alive_mutex) == 0)
	{
		all_alive = table->all_alive;
		if (pthread_mutex_unlock(&table->alive_mutex) != 0)
			return (-1);
		return (all_alive);
	}
	else
		return (-1);
}

int	get_time(t_table *table, const char which_time)
{
	int	retval;

	retval = 0;
	if (table == NULL)
		return (-1);
	if (pthread_mutex_lock(&table->time_mutex) == 0)
	{
		if (which_time == 'd')
			retval = table->time_d_e_s[0];
		else if (which_time == 'e')
			retval = table->time_d_e_s[1];
		else if (which_time == 's')
			retval = table->time_d_e_s[2];
		else
			retval = -1;
		if (pthread_mutex_unlock(&table->time_mutex) != 0)
			return (-1);
	}
	return (retval);
}

int	get_have_eaten(t_philo *philo)
{
	int	have_eaten;

	if (philo == NULL)
		return (-1);
	if (pthread_mutex_lock(&philo->philo_mutex) == 0)
	{
		have_eaten = philo->have_eaten;
		if (pthread_mutex_unlock(&philo->philo_mutex) != 0)
			return (-1);
		return (have_eaten);
	}
	else
		return (-1);
}

long int	get_start_time(t_table *table)
{
	long int	start_time;

	if (table == NULL)
		return (-1);
	if (pthread_mutex_lock(&table->start_time_mutex) == 0)
	{
		start_time = table->start_time;
		if (pthread_mutex_unlock(&table->start_time_mutex) != 0)
			return (-1);
		return (start_time);
	}
	else
		return (-1);
}

long int	get_last_eat(t_philo *philo)
{
	long int	last_eat;

	if (philo == NULL)
		return (-1);
	if (pthread_mutex_lock(&philo->philo_mutex) == 0)
	{
		last_eat = philo->last_eat;
		if (pthread_mutex_unlock(&philo->philo_mutex) != 0)
			return (-1);
		return (last_eat);
	}
	else
		return (-1);
}
