/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:27:05 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/25 19:09:47 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap(t_stack **stack, char *op)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return (NULL);
	first = pop_from_stack(stack);
	second = pop_from_stack(stack);
	if (!first || !second)
		return (NULL);
	push_to_stack(stack, first);
	push_to_stack(stack, second);
	return (op);
}

char	*push(t_stack **dst, t_stack **src, char *op)
{
	t_stack	*tmp;

	tmp = pop_from_stack(src);
	if (!tmp)
		return (NULL);
	push_to_stack(dst, tmp);
	return (op);
}

char	*rotate(t_stack **stack, char *op)
{
	t_stack	*node;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return (NULL);
	node = pop_from_stack(stack);
	if (!node)
		return (NULL);
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (op);
}

char	*reverse_rotate(t_stack **stack, char *op)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return (NULL);
	tmp = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->previous->next = NULL;
	last = pop_from_stack(stack);
	if (!last)
		return (NULL);
	*stack = tmp;
	push_to_stack(stack, last);
	return (op);
}
