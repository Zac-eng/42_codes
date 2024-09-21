/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:20:25 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/08 22:14:13 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_times(int argc, char **argv, int *vars);
static int	create_table_mutexes(t_table *table);

int	create_table(int argc, char **argv, t_table *table)
{
	if (argv == NULL || table == NULL || (argc != 5 && argc != 6))
		return (-1);
	table->all_alive = 1;
	table->philo_num = pos_atoi(argv[1]);
	if (table->philo_num < 0)
		return (-1);
	if (get_times(argc, argv, &table->time_d_e_s[0]) != 0)
		return (-1);
	if (get_time_ms(&(table->start_time)) != 0)
		return (-1);
	table->start_time += table->philo_num * 10;
	if (argc == 6)
	{
		table->num_eat = (long int)pos_atoi(argv[5]);
		if (table->num_eat < 0)
			return (-1);
	}
	if (argc == 5)
		table->num_eat = LONG_MAX;
	if (create_table_mutexes(table) < 0)
		return (-1);
	table->forks = create_forks(table->philo_num);
	if (table->forks == NULL)
		return (destroy_table_mutexes(table) * 0 - 1);
	return (0);
}

static int	get_times(int argc, char **argv, int *vars)
{
	if (argv == NULL || vars == NULL)
		return (-1);
	if (argc != 5 && argc != 6)
		return (-1);
	vars[0] = pos_atoi(argv[2]);
	vars[1] = pos_atoi(argv[3]);
	vars[2] = pos_atoi(argv[4]);
	if (vars[0] <= 0 || vars[1] <= 0 || vars[2] <= 0)
		return (-1);
	return (0);
}

static int	create_table_mutexes(t_table *table)
{
	if (pthread_mutex_init(&(table->alive_mutex), NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&(table->time_mutex), NULL) != 0)
	{
		pthread_mutex_destroy(&(table->alive_mutex));
		return (-1);
	}
	if (pthread_mutex_init(&(table->start_time_mutex), NULL) != 0)
	{
		pthread_mutex_destroy(&(table->time_mutex));
		pthread_mutex_destroy(&(table->alive_mutex));
		return (-1);
	}
	return (0);
}

int	destroy_table_mutexes(t_table *table)
{
	pthread_mutex_destroy(&(table->time_mutex));
	pthread_mutex_destroy(&(table->alive_mutex));
	pthread_mutex_destroy(&(table->start_time_mutex));
	return (0);
}
