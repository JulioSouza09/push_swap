/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:40:21 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/30 11:29:26 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_idx(t_stack **stack, int nbr)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		if (nbr == tmp->content)
			return (i);
		tmp = tmp->next;
		++i;
	}
	return (-1);
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

int	get_next_idx(t_stack **stack, int nbr)
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

t_moves	count_operations(t_stack **stack, int nbr, int size)
{
	int		current;
	t_moves	moves;

	current = get_idx(stack, nbr);
	ft_memset(&moves, 0, sizeof(t_moves));
	if (current <= size / 2)
		moves.rn = current;
	else
		moves.rrn = size - current;
	moves.total = moves.rn + moves.rrn;
	return (moves);
}

void	calc_moves_per_node(t_stack **stack, int size)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_memset(&tmp->moves, 0, sizeof(t_moves));
		tmp->moves = count_operations(stack, tmp->content, size);
		tmp = tmp->next;
	}
}

void	calc_all_moves(t_app *app)
{
	calc_moves_per_node(app->a, app->a_size);
	calc_moves_per_node(app->b, app->b_size);
}

int	min(int nbr1, int nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}

int	max(int nbr1, int nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}

void	find_rr(int nbr_a, int nbr_b, t_moves *moves)
{
	int	biggest;
	int	smallest;

	biggest = max(nbr_a, nbr_b);
	smallest = min(nbr_a, nbr_b);
	moves->rr = smallest;
	if (biggest == nbr_a)
		moves->ra = biggest - smallest;
	else
		moves->rb = biggest - smallest;
}

void	find_rrr(int nbr_a, int nbr_b, t_moves *moves)
{
	int	biggest;
	int	smallest;

	biggest = max(nbr_a, nbr_b);
	smallest = min(nbr_a, nbr_b);
	moves->rrr = smallest;
	if (biggest == nbr_a)
		moves->rra = biggest - smallest;
	else
		moves->rrb = biggest - smallest;
}

t_stack	*get_final_target(t_stack **b, int nbr)
{
	t_stack	*target;
	int		min;
	int		max;

	min = get_min(b);
	max = get_max(b);
	if (nbr > max || nbr < min)
		target = get_target(b, max);
	else
		target = get_target(b, get_next_idx(b, nbr));
	return (target);
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

t_stack	*get_final_target_a(t_stack **a, int nbr)
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

int	calc_total_moves(t_stack *node, t_stack **b_head, t_moves *moves)
{
	t_stack	*b;

	b = get_final_target(b_head, node->content);
	if (!b)
		return (-1);
	if (node->moves.rn && b->moves.rn)
		find_rr(node->moves.rn, b->moves.rn, moves);
	else if (node->moves.rrn && b->moves.rrn)
		find_rrr(node->moves.rrn, b->moves.rrn, moves);
	else
	{
		moves->ra = node->moves.rn;
		moves->rra = node->moves.rrn;
		moves->rb = b->moves.rn;
		moves->rrb = b->moves.rrn;
	}
	moves->total = moves->ra + moves->rb + moves->rrb + moves->rr + moves->rra + moves->rrr;
	return (moves->total);
}

t_stack	*find_cheapest(t_app *app)
{
	t_stack	*a;
	t_stack	*cheapest;
	t_moves	moves;
	int		candidate;

	a = *app->a;
	ft_memset(&moves, 0, sizeof(t_moves));
	candidate = calc_total_moves(a, app->b, &moves);
	cheapest = a;
	cheapest->moves = moves;
	a = a->next;
	while (a)
	{
		ft_memset(&moves, 0, sizeof(t_moves));
		if (calc_total_moves(a, app->b, &moves) < candidate)
		{
			cheapest = a;
			cheapest->moves = moves;
		}
		a = a->next;
	}
	return (cheapest);
}
