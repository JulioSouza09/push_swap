/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:01:38 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/09/03 14:58:45 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
void	exec_single_moves(t_app *app, t_stack *cheapest)
{
	if (cheapest->moves.ra)
		exec_one_p(app->a, ra, cheapest->moves.ra);
	if (cheapest->moves.rra)
		exec_one_p(app->a, rra, cheapest->moves.rra);
	if (cheapest->moves.rb)
		exec_one_p(app->b, rb, cheapest->moves.rb);
	if (cheapest->moves.rrb)
		exec_one_p(app->b, rrb, cheapest->moves.rrb);
}

static
void	exec_double_moves(t_app *app, t_stack *cheapest)
{
	if (cheapest->moves.rr)
		exec_two_p(app, rr, cheapest->moves.rr);
	if (cheapest->moves.rrr)
		exec_two_p(app, rrr, cheapest->moves.rrr);
}

void	send_to_b(t_app *app)
{
	t_stack	*cheapest;

	pb(app);
	pb(app);
	while (app->a_size > 3)
	{
		calc_all_moves(app);
		cheapest = find_cheapest(app);
		if (!cheapest)
			return (ft_putendl_fd("Error", 2));
		exec_single_moves(app, cheapest);
		exec_double_moves(app, cheapest);
		pb(app);
	}
}

void	send_to_a(t_app *app)
{
	t_stack	*target;

	while (*app->b)
	{
		target = get_a_target(app->a, (*app->b)->content);
		move_to_top(app->a, target->content, app->a_size);
		pa(app);
	}
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
