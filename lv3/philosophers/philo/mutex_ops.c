/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:48:07 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/08 22:13:53 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_fork_indexes(int philo_id, int philo_num, int *fork_indexes);

t_mutex	*create_forks(int philo_num)
{
	t_mutex	*mutexes;
	int		iter;

	iter = 0;
	mutexes = (t_mutex *)malloc(sizeof(t_mutex) * philo_num);
	if (mutexes == NULL)
		return (NULL);
	while (iter < philo_num)
	{
		if (pthread_mutex_init(&mutexes[iter], NULL) != 0)
			return (destruct_mutexes(mutexes, iter));
		iter += 1;
	}
	return (mutexes);
}

void	*destruct_mutexes(t_mutex *mutexes, int mutex_num)
{
	int	iter;

	iter = 0;
	if (mutexes == NULL)
		return (NULL);
	while (iter < mutex_num)
	{
		pthread_mutex_destroy(&mutexes[iter]);
		iter += 1;
	}
	free(mutexes);
	return (NULL);
}

int	lock_forks(t_philo *philo)
{
	t_table	*table;
	int		fork_index[2];

	if (philo == NULL || philo->table == NULL)
		return (0);
	table = philo->table;
	set_fork_indexes(philo->philo_id, table->philo_num, &fork_index[0]);
	if (pthread_mutex_lock(&(table->forks[fork_index[0]])) != 0)
		return (-1);
	if (pthread_mutex_lock(&(table->forks[fork_index[1]])) != 0)
	{
		pthread_mutex_unlock(&(table->forks[fork_index[0]]));
		return (-1);
	}
	return (0);
}

int	unlock_forks(t_philo *philo)
{
	t_table	*table;
	int		fork_index[2];

	if (philo == NULL || philo->table == NULL)
		return (0);
	table = philo->table;
	fork_index[0] = philo->philo_id - 1;
	if (philo->philo_id == philo->table->philo_num)
		fork_index[1] = 0;
	else
		fork_index[1] = philo->philo_id;
	if (pthread_mutex_unlock(&(table->forks[fork_index[0]])) != 0)
	{
		pthread_mutex_unlock(&(table->forks[fork_index[1]]));
		return (-1);
	}
	if (pthread_mutex_unlock(&(table->forks[fork_index[1]])) != 0)
		return (-1);
	return (0);
}

static void	set_fork_indexes(int philo_id, int philo_num, int *fork_indexes)
{
	int	left;
	int	right;

	left = philo_id - 1;
	if (philo_id == philo_num)
		right = 0;
	else
		right = philo_id;
	if (philo_id % 2 == 0)
	{
		fork_indexes[0] = left;
		fork_indexes[1] = right;
	}
	else
	{
		fork_indexes[0] = right;
		fork_indexes[1] = left;
	}
}
