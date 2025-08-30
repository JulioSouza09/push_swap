/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:40:21 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/30 20:38:15 by jcesar-s         ###   ########.fr       */
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

static
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

static
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
