/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:42:56 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/09/03 12:15:58 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
void	sort_two(t_stack **a)
{
	if (!a || !*a)
		return ;
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

static
void	sort_three(t_stack **a)
{
	int	max;

	if (!a || !*a)
		return ;
	max = get_max(a);
	if (max == (*a)->content)
		ra(a);
	else if (max == (*a)->next->content)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

static
void	sort_bigger(t_app *app)
{
	int		min;

	send_to_b(app);
	sort_three(app->a);
	send_to_a(app);
	min = get_min(app->a);
	move_to_top(app->a, min, app->a_size);
}

void	sort_stack(t_app *app)
{
	if (is_sorted(app->a))
		return ;
	if (app->a_size == 2)
		sort_two(app->a);
	else if (app->a_size == 3)
		sort_three(app->a);
	else if (app->a_size > 3)
		sort_bigger(app);
}
