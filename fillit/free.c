/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:03:56 by hirenpat          #+#    #+#             */
/*   Updated: 2019/02/16 18:03:58 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		free_grid(t_tetris *t)
{
	int	x;

	x = 0;
	if (!t->grid)
		return (0);
	while (x < t->grid_size)
	{
		free(t->grid[x]);
		x++;
	}
	free(t->grid);
	return (1);
}

int		free_points(t_tetris *t)
{
	int	p_i;
	int	s_i;

	s_i = -1;
	if (!t->points)
		return (0);
	while (++s_i < t->t_count)
	{
		p_i = -1;
		while (++p_i < 4)
		{
			free(t->points[s_i][p_i]);
		}
		free(t->points[s_i]);
	}
	free(t->points);
	return (1);
}

int		free_world(t_tetris *t, char *buffer)
{
	free(buffer);
	free_grid(t);
	free_points(t);
	free(t);
	return (1);
}
