/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:09:29 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/30 20:37:44 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
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

static
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

static
int	calc_total_moves(t_stack *node, t_stack **b_head, t_moves *m)
{
	t_stack	*b;

	b = get_b_target(b_head, node->content);
	if (!b)
		return (-1);
	if (node->moves.rn && b->moves.rn)
		find_rr(node->moves.rn, b->moves.rn, m);
	else if (node->moves.rrn && b->moves.rrn)
		find_rrr(node->moves.rrn, b->moves.rrn, m);
	else
	{
		m->ra = node->moves.rn;
		m->rra = node->moves.rrn;
		m->rb = b->moves.rn;
		m->rrb = b->moves.rrn;
	}
	m->total = m->ra + m->rb + m->rrb + m->rr + m->rra + m->rrr;
	return (m->total);
}

static
int	update_cheapest(t_stack **cheapest, t_stack *a, t_app *app, int *best_score)
{
	t_moves	moves;
	int		score;

	ft_memset(&moves, 0, sizeof(t_moves));
	score = calc_total_moves(a, app->b, &moves);
	if (score == -1)
		return (-1);
	if (score < *best_score)
	{
		*cheapest = a;
		(*cheapest)->moves = moves;
		*best_score = score;
	}
	return (0);
}

t_stack	*find_cheapest(t_app *app)
{
	t_stack	*a;
	t_stack	*cheapest;
	int		best_score;

	if (!app || !app->a || !*app->a || !app->b || !*app->b)
		return (NULL);
	a = *app->a;
	best_score = INT_MAX;
	cheapest = NULL;
	while (a)
	{
		if (update_cheapest(&cheapest, a, app, &best_score) == -1)
			return (NULL);
		a = a->next;
	}
	return (cheapest);
}
