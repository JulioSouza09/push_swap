/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:37:12 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/28 19:19:18 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp)
	{
		ft_printf("content: %d\t", tmp->content);
		if (tmp->next)
			ft_printf("next: %d\t\t", tmp->next->content);
		if (tmp->previous)
			ft_printf("previous: %d", tmp->previous->content);
		ft_printf("\n");
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_app	*app;

	if (argc == 1)
		return (1);
	app = init_all(argc, argv);
	if (!app)
		return (2);
	//ft_printf("%d\n", get_next_idx(app->a, 6));
	calc_moves_per_node(app->a, app->a_size);
	//sort_stack(app->a_size, app->a, app->b);
	//move_to_top(app->a, -1, app->a_size);
	//print_stack(app->a);
	free_all(app);
	return (0);
}
