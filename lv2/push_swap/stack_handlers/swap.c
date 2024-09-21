/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:05:41 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/11 22:08:07 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a)
{
	int	first_element;
	int	second_element;

	if (a->current_size <= 1)
		return ;
	first_element = pop_top(a);
	second_element = pop_top(a);
	push_top(a, first_element);
	push_top(a, second_element);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int	first_element;
	int	second_element;

	if (b->current_size <= 1)
		return ;
	first_element = pop_top(b);
	second_element = pop_top(b);
	push_top(b, first_element);
	push_top(b, second_element);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	int	first_element;
	int	second_element;

	if (a->current_size <= 1 || b->current_size <= 1)
		return ;
	first_element = pop_top(a);
	second_element = pop_top(a);
	push_top(a, first_element);
	push_top(a, second_element);
	first_element = pop_top(b);
	second_element = pop_top(b);
	push_top(b, first_element);
	push_top(b, second_element);
	write(1, "ss\n", 3);
}
