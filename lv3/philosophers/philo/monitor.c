/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:27:27 by hmiyazak          #+#    #+#             */
/*   Updated: 2024/05/08 22:24:02 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_finished(t_table *table, int philo_id);
static int	check_hunger(t_table *table, int philo_id, long int c_time);

void	monitor(t_table *table)
{
	long int	c_time;
	int			finished;
	int			iter;

	while (1)
	{
		iter = 0;
		finished = 1;
		if (get_time_ms(&c_time) < 0)
			break ;
		if (get_allalive(table) != 1)
			break ;
		while (iter < table->philo_num)
		{
			if (check_finished(table, iter) == 0)
				finished = 0;
			if (check_hunger(table, iter, c_time) != 0)
				break ;
			iter++;
		}
		if (finished == 1)
			break ;
	}
	switch_allalive(table);
}

static int	check_finished(t_table *table, int philo_id)
{
	int	have_eaten;

	if (table == NULL)
		return (-1);
	have_eaten = get_have_eaten(&table->philos[philo_id]);
	if (have_eaten < 0)
		return (-1);
	else if (have_eaten >= table->num_eat)
		return (1);
	else
		return (0);
}

static int	check_hunger(t_table *table, int philo_id, long int c_time)
{
	long int	last_eat;

	if (table == NULL)
		return (-1);
	last_eat = get_last_eat(&table->philos[philo_id]);
	if (last_eat < 0)
		return (-1);
	if (c_time - last_eat > get_time(table, 'd'))
	{
		died(philo_id + 1, table);
		return (1);
	}
	else
		return (0);
}
