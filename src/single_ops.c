/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:27:05 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/24 19:48:21 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stack)->next)
		return ;
	first = pop_from_stack(stack);
	second = pop_from_stack(stack);
	if (!first || !second)
		return ;
	push_to_stack(stack, first);
	push_to_stack(stack, second);
}

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	tmp = pop_from_stack(src);
	if (!tmp)
		return ;
	push_to_stack(dst, tmp);
}

void	rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;

	if (!(*stack)->next)
		return ;
	node = pop_from_stack(stack);
	if (!node)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack)->next)
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
