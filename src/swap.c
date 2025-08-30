/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:27:44 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/30 20:41:39 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = pop_from_stack(stack);
	second = pop_from_stack(stack);
	if (!first || !second)
		return ;
	push_to_stack(stack, first);
	push_to_stack(stack, second);
}

void	sa(t_stack **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **b)
{
	swap(b);
	ft_putendl_fd("sa", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
