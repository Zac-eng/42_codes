/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:22:02 by hmiyazak          #+#    #+#             */
/*   Updated: 2023/10/23 22:41:31 by hmiyazak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				body;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		current_size;
	int		max_size;
}	t_stack;

t_stack	*create_stack(int node_num, int argc, char **argv);
t_stack	*initialize_stack(int node_num);
void	create_input_list(int argc, char **argv, int *foundation);
void	compress_list(int list_size, int *to_be_compressed);
void	push_top(t_stack *stack, int new_element);
void	push_bottom(t_stack *stack, int new_element);
int		pop_top(t_stack *stack);
int		pop_bottom(t_stack *stack);
void	rotate(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	smallest_nodes_operation(t_stack *stack);
void	four_nodes_operation(t_stack *stack_a, t_stack *stack_b);
void	five_nodes_operation(t_stack *stack_a, t_stack *stack_b);
void	many_nodes_operation(t_stack *stack_a, t_stack *stack_b);
int		atoi_or_exit(char *should_num);
int		ft_isspace(char c);
void	error_and_exit(void);

#endif
