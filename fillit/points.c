/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:41:12 by hirenpat          #+#    #+#             */
/*   Updated: 2019/02/15 21:41:14 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		set_points(t_tetris *t, char *t_shape_buff)
{
	int x;
	int y;
	int i;

	x = -1;
	y = -1;
	i = 0;
	while (++y < 4 && *t_shape_buff != '\0')
	{
		x = -1;
		while (++x < 4 && *t_shape_buff != '\0')
		{
			if (*t_shape_buff == '#')
			{
				t->points[t->tet_i][i] = (t_point *)malloc(sizeof(t_point));
				t->points[t->tet_i][i]->x = x;
				t->points[t->tet_i][i++]->y = y;
			}
			else if (*t_shape_buff != '.')
				return (0);
			t_shape_buff++;
		}
	}
	return (i == 4 ? 1 : 0);
}

int		s_p(t_tetris *t, int x, int y)
{
	int i;

	i = -1;
	while (++i <= 3)
	{
		if ((t->points[t->tet_i][i]->x == x) &&
		(t->points[t->tet_i][i]->y == y))
			return (1);
	}
	return (0);
}

int		check_points(t_tetris *t, int p_i, int x, int y)
{
	if (p_i >= 3)
		return (1);
	if ((x >= 0 && (x < t->grid_size)) && (y >= 0 && (y < t->grid_size)))
	{
		if (t->grid[y][x] == '.')
		{
			x += (t->points[t->tet_i][p_i + 1]->x -
			t->points[t->tet_i][p_i]->x);
			y += (t->points[t->tet_i][p_i + 1]->y -
			t->points[t->tet_i][p_i]->y);
			p_i++;
			return (check_points(t, p_i, x, y));
		}
	}
	return (0);
}
