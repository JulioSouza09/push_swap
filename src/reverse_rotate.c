/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:18:31 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/26 10:23:25 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack	**stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->previous->next = NULL;
	last = pop_from_stack(stack);
	if (!last)
		return ;
	*stack = tmp;
	push_to_stack(stack, last);
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}
