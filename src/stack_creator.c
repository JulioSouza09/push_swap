/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:34:34 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/25 16:28:09 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

t_stack	**create_stack(void)
{
	t_stack	**head;

	head = ft_calloc(1, sizeof(t_stack *));
	if (!head)
		return (NULL);
	*head = NULL;
	return (head);
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

static int	is_valid_char(char c)
{
	if (c == 39 || c == '-' || c == '+')
		return (1);
	return (0);
}

int	fill_stack(t_stack **head, int argc, char **argv)
{
	t_stack	*node;
	char	*str;
	int		i;
	long	nbr;
	int		words;

	i = 0;
	while (i < argc)
	{
		words = count_words(argv[i], ' ');
		if (words == 0 || words > 1)
			return (1);
		str = skip_spaces(argv[i]);
		if (!ft_isdigit(*str) && !is_valid_char(*str))
			return (2);
		nbr = ft_atol(str);
		if (nbr < INT_MIN || nbr > INT_MAX || is_duplicate(head, nbr))
			return (3);
		node = create_new_node((int)nbr);
		if (!node)
			return (4);
		push_to_stack(head, node);
		++i;
	}
	return (0);
}
