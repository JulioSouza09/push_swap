/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:37:14 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/29 19:44:24 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->previous && tmp->previous->content > tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = (*stack)->next;
	max = tmp->previous->content;
	while (tmp)
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_stack **stack)
{
	t_stack	*tmp;
	int		min;

	tmp = (*stack)->next;
	min = tmp->previous->content;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	exec_one_param(t_stack **x, void (*op)(t_stack**x), int nbr)
{
	int	i;
	
	i = 0;
	while (i++ < nbr)
		op(x);
}

void	exec_two_param(t_app *app, void (*op)(t_stack**a,t_stack**b), int nbr)
{
	int	i;
	
	i = 0;
	while (i++ < nbr)
		op(app->a, app->b);
}

void	move_to_top(t_stack **stack, int nbr, int size)
{
	int	current;

	current = -1;
	while (current)
	{
		current = get_idx(stack, nbr);
		if (current == 0)
			break ;
		else if (current <= size / 2)
			ra(stack);
		else
			rra(stack);
	}
}
