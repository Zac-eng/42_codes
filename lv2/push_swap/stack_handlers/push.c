/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:32:41 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/11/06 23:07:10 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	poped_element;

	if (stack_b->current_size == 0)
		return ;
	poped_element = pop_top(stack_b);
	push_top(stack_a, poped_element);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	poped_element;

	if (stack_a->current_size == 0)
		return ;
	poped_element = pop_top(stack_a);
	push_top(stack_b, poped_element);
	write(1, "pb\n", 3);
}
