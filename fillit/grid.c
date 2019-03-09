/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:39:22 by hirenpat          #+#    #+#             */
/*   Updated: 2019/02/15 21:39:26 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**make_grid(int size)
{
	char	**grid;
	int		x;
	int		y;

	x = -1;
	grid = malloc(size * sizeof(char *));
	while (++x < size)
		grid[x] = malloc(size * sizeof(char));
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			grid[y][x] = '.';
		}
	}
	return (grid);
}

void		resize_grid(t_tetris *t)
{
	int		x;

	x = -1;
	while (++x < t->grid_size)
		free(t->grid[x]);
	free(t->grid);
	t->grid_size++;
	t->grid = make_grid(t->grid_size);
}

void		print_grid(char **str, int size)
{
	int		x;
	int		y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			ft_putchar(str[y][x]);
		}
		ft_putchar('\n');
	}
}

int			put_on_grid(t_tetris *t, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (((x >= 0) && x < t->grid_size) && (y >= 0 &&
		y < t->grid_size) && t->grid[y][x] == '.')
		{
			t->grid[y][x] = t->tet_i + 'A';
			if (i < 3)
			{
				x += t->points[t->tet_i][i + 1]->x -
				t->points[t->tet_i][i]->x;
				y += t->points[t->tet_i][i + 1]->y -
				t->points[t->tet_i][i]->y;
			}
			i++;
		}
		else
			return (0);
	}
	return (1);
}
