/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:08:36 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/26 10:23:11 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack	**stack)
{
	t_stack	*node;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	node = pop_from_stack(stack);
	if (!node)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
