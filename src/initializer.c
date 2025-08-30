/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcesar-s <jcesar-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:39:27 by jcesar-s          #+#    #+#             */
/*   Updated: 2025/08/30 20:38:37 by jcesar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static
void	ft_error(t_app	*app)
{
	ft_putendl_fd("Error", 2);
	free_all(app);
}

t_app	*init_all(int argc, char **argv)
{
	t_prepr	ini;
	t_app	*app;

	app = create_app();
	if (!app)
		return (NULL);
	if (prep_input(&ini, argc, argv))
	{
		ft_error(app);
		return (NULL);
	}
	if (fill_stack(app->a, ini.len, ini.input))
	{
		ft_error(app);
		if (ini.is_freeable)
			free_matrix(ini.input);
		return (NULL);
	}
	if (ini.is_freeable)
		free_matrix(ini.input);
	app->a_size = ini.len;
	return (app);
}

t_app	*create_app(void)
{
	t_app	*app;

	app = ft_calloc(1, sizeof(t_app));
	if (!app)
		return (NULL);
	app->a = create_stack();
	if (!app->a)
	{
		free(app);
		return (NULL);
	}
	app->b = create_stack();
	if (!app->b)
	{
		free_stack(app->a);
		free(app);
		return (NULL);
	}
	return (app);
}
