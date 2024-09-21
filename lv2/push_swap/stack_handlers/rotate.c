/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:38:34 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/31 22:52:51 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack *stack);

void	rotate(t_stack *stack)
{
	int	poped_element;

	if (stack == NULL)
		exit(1);
	poped_element = pop_top(stack);
	push_bottom(stack, poped_element);
}

void	ra(t_stack *stack_a)
{
	if (stack_a == NULL)
		exit(1);
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	if (stack_b == NULL)
		exit(1);
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
