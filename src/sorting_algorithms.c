/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:42:56 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/29 20:21:57 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if (!a || !*a)
		return ;
	if ((*a)->content < (*a)->next->content)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int	max;

	if (!a || !*a)
		return ;
	max = get_max(a);
	if (max == (*a)->content)
		ra(a);
	while (!is_sorted(a))
	{
		if ((*a)->content > (*a)->next->content)
			sa(a);
		if (!is_sorted(a))
			rra(a);
	}
}

void	sort_bigger(t_app *app)
{
	t_stack	*cheapest;
	int		min;
	int		max;

	pb(app->b, app->a);
	pb(app->b, app->a);
	app->a_size -= 2;
	app->b_size = 2;
	while (app->a_size > 3)
	{
		calc_all_moves(app);
		cheapest = find_cheapest(app);
		if (cheapest->moves.ra)
			exec_one_param(app->a, ra, cheapest->moves.ra);
		if (cheapest->moves.rra)
			exec_one_param(app->a, rra, cheapest->moves.rra);
		if (cheapest->moves.rb)
			exec_one_param(app->b, rb, cheapest->moves.rb);
		if (cheapest->moves.rrb)
			exec_one_param(app->b, rrb, cheapest->moves.rrb);
		if (cheapest->moves.rr)
			exec_two_param(app, rr, cheapest->moves.rr);
		if (cheapest->moves.rrr)
			exec_two_param(app, rrr, cheapest->moves.rrr);
		pb(app->b, app->a);
		app->a_size--;
		app->b_size++;
	}
	sort_three(app->a);
	while (*app->b)
	{
		min = get_min(app->a);
		max = get_max(app->a);
		if ((*app->b)->content > min && (*app->b)->content < max)
			move_to_top(app->a, max, app->a_size);
		else if ((*app->b)->content > min && (*app->b)->content < max)
			move_to_top(app->a, min, app->a_size);
		else if ((*app->b)->content < min)
			move_to_top(app->a, min, app->a_size);
		pa(app->a, app->b);
		app->b_size--;
		app->a_size++;
	}
}

void	sort_stack(t_app *app)
{
	if (app->a_size == 2)
		sort_two(app->a);
	else if (app->a_size == 3)
		sort_three(app->a);
	else if (app->a_size > 3)
		sort_bigger(app);
}
