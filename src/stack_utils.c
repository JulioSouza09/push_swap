/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:17:47 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/24 19:36:36 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*free_node;

	tmp = *head;
	free_node = NULL;
	while (tmp)
	{
		free_node = tmp;
		tmp = tmp->next;
		free(free_node);
	}
	free(head);
}

void	push_to_stack(t_stack **dst, t_stack *node)
{
	t_stack	*tmp;

	if (!*dst)
	{
		*dst = node;
		return ;
	}
	tmp = *dst;
	*dst = node;
	(*dst)->next = tmp;
	tmp->previous = node;
}

t_stack	*pop_from_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return (NULL);
	tmp = *stack;
	*stack = tmp->next;
	if (*stack)
		(*stack)->previous = NULL;
	tmp->next = NULL;
	tmp->previous = NULL;
	return (tmp);
}
