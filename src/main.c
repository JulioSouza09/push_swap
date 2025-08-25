/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:37:12 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/25 15:41:24 by jcesar-s         ###   ########.fr       */
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
	selection_sort(app->a);
	free_all(app);
	return (0);
}
