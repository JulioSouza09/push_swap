/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:17:47 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/22 18:20:47 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

static int	is_duplicate(t_stack **head, int nbr)
{
	t_stack	*tmp;

	if (!*head)
		return (0);
	tmp = *head;
	while (tmp)
	{
		if (tmp->content == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	fill_stack(t_stack **head, int argc, char **argv)
{
	t_stack	*node;
	char	*str;
	int		i;
	long	nbr;

	i = 0;
	while (i < argc)
	{
		str = skip_spaces(argv[i]);
		if (!ft_isdigit(*str))
			return (1);
		nbr = ft_atol(str);
		if (nbr < INT_MIN || nbr > INT_MAX || is_duplicate(head, nbr))
			return (2);
		node = create_new_node((int)nbr);
		if (!node)
			return (3);
		push_to_stack(head, node);
		++i;
	}
	return (0);
}

t_stack	**create_stack(void)
{
	t_stack	**head;

	head = malloc(sizeof(t_stack *));
	if (!head)
		return (NULL);
	*head = NULL;
	return (head);
}

void	free_stack(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*free_node;

	tmp = *head;
	free_node = NULL;
	while (tmp)
	{
		free_node = tmp;
		tmp = tmp->next;
		free(free_node);
	}
	free(head);
}

t_stack	*create_new_node(int content)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	push_to_stack(t_stack **head, t_stack *node)
{
	t_stack	*tmp;

	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = *head;
	*head = node;
	node->next = tmp;
	tmp->previous = node;
}
