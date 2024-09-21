/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:08:50 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/06/11 10:51:59 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_num(char input);
static int	check_over(long long int current, char next, int minus_flg);
static int	handle_sign(char **num_str);
static int	ft_isspace(char targ);

int	ft_atoi(const char *str)
{
	long long int	current_num;
	int				minus_flg;
	char			*str_use;

	current_num = 0;
	str_use = (char *) str;
	while (ft_isspace(*str_use) == 1)
		str_use += 1;
	minus_flg = handle_sign(&str_use);
	while (is_num(*str_use) == 1)
	{
		if (minus_flg == 1 && check_over(current_num, *str_use, minus_flg) == 1)
			return (0);
		else if (check_over(current_num, *str_use, minus_flg) == 1)
			return (-1);
		else
		{
			current_num = current_num * 10 + (*str_use - '0');
			str_use += 1;
		}
	}
	if (minus_flg == 1)
		current_num *= -1;
	return (current_num);
}

static int	handle_sign(char **num_str)
{
	if (**num_str == '+')
		*num_str += 1;
	else if (**num_str == '-')
	{
		*num_str += 1;
		return (1);
	}
	return (0);
}

static int	is_num(char input)
{
	if ('0' <= input && input <= '9')
		return (1);
	else
		return (0);
}

static int	ft_isspace(char targ)
{
	if (targ == ' ')
		return (1);
	else if (targ == '\t')
		return (1);
	else if (targ == '\n')
		return (1);
	else if (targ == '\v')
		return (1);
	else if (targ == '\f')
		return (1);
	else if (targ == '\r')
		return (1);
	else
		return (0);
}

static int	check_over(long long int current, char next, int minus_flg)
{
	char	limit;

	if (minus_flg == 0)
		limit = LLONG_MAX % 10 - 1 + '0';
	else
		limit = LLONG_MAX % 10 + '0';
	if (current > LLONG_MAX / 10)
		return (1);
	else if (current == LLONG_MAX / 10)
	{
		if (next > limit)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
