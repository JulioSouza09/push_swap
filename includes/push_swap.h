/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:07:43 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/29 11:38:56 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0

# include "libft.h"

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rn;
	int	rrn;
	int	rr;
	int	rrr;
	int	total;
}	t_moves;

typedef struct s_stack
{
	int				content;
	t_moves			moves;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_prepr
{
	char	**input;
	int		is_freeable;
	int		len;
}	t_prepr;

typedef struct s_app
{
	t_stack	**a;
	t_stack	**b;
	int		a_size;
	int		b_size;
}	t_app;

/***** Stack utils *****/
t_stack	*pop_from_stack(t_stack **stack);
void	push_to_stack(t_stack **head, t_stack *node);
void	free_stack(t_stack **head);

/***** Stack creator *****/
t_stack	**create_stack(void);
t_stack	*create_new_node(int content);
int		fill_stack(t_stack **head, int argc, char **argv);

/***** Parser utils *****/
char	*skip_spaces(char *str);
long	ft_atol(char *str);
int		is_duplicate(t_stack **head, int nbr);
int		prep_input(t_prepr *vars, int argc, char **argv);

/***** Swap *****/
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/***** Push *****/
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

/***** Rotate *****/
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/***** Reverse rotate *****/
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/***** Multiple operations *****/
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/***** Sorting utils *****/
void	sort_stack(t_app *app);

/***** Initializer *****/
t_app	*create_app(void);
t_app	*init_all(int argc, char **argv);

/***** Utils *****/
void	free_matrix(char **matrix);
void	free_all(t_app *app);
int		count_matrix(char **matrix);

int		get_max(t_stack **stack);
int		get_min(t_stack **stack);
int		get_idx(t_stack **stack, int nbr);
int		is_sorted(t_stack **stack);
int		get_next_idx(t_stack **stack, int nbr);
void	move_to_top(t_stack **stack, int nbr, int size);
void	calc_moves_per_node(t_stack **stack, int size);
void	calc_all_moves(t_app *app);
t_stack	*find_cheapest(t_app *app);
void	exec_one_param(t_app *app, void (*op)(t_stack**a), int nbr);
void	exec_two_param(t_app *app, void (*op)(t_stack**a,t_stack**b), int nbr);

#endif
