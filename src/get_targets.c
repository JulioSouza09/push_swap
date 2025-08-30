/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:00:12 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/30 20:07:15 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_max(t_stack **stack, int nbr)
{
	t_stack	*tmp;
	int		new_max;

	tmp = (*stack)->next;
	new_max = tmp->previous->content;
	while (tmp)
	{
		if ((new_max < tmp->content && tmp->content < nbr) || new_max > nbr)
			new_max = tmp->content;
		tmp = tmp->next;
	}
	return (new_max);
}

int	get_next_min(t_stack **stack, int nbr)
{
	t_stack	*tmp;
	int		new_min;

	tmp = (*stack)->next;
	new_min = tmp->previous->content;
	while (tmp)
	{
		if ((new_min > tmp->content && tmp->content > nbr) || new_min < nbr)
			new_min = tmp->content;
		tmp = tmp->next;
	}
	return (new_min);
}

t_stack	*get_target(t_stack **stack, int nbr)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (nbr == tmp->content)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_stack	*get_b_target(t_stack **b, int nbr)
{
	t_stack	*target;
	int		min;
	int		max;

	min = get_min(b);
	max = get_max(b);
	if (nbr > max || nbr < min)
		target = get_target(b, max);
	else
		target = get_target(b, get_next_max(b, nbr));
	return (target);
}

t_stack	*get_a_target(t_stack **a, int nbr)
{
	t_stack	*target;
	int		min;
	int		max;

	min = get_min(a);
	max = get_max(a);
	if (nbr > max || nbr < min)
		target = get_target(a, min);
	else
		target = get_target(a, get_next_min(a, nbr));
	return (target);
}
