/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:52:11 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/14 23:08:10 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack *stack);

static void	reverse_rotate(t_stack *stack)
{
	int	poped_element;

	if (stack == NULL)
		exit(1);
	poped_element = pop_bottom(stack);
	push_top(stack, poped_element);
}

void	rra(t_stack *stack_a)
{
	if (stack_a == NULL)
		exit(1);
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	if (stack_b == NULL)
		exit(1);
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		exit(1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
