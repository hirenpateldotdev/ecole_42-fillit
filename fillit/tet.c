/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:50:58 by hirenpat          #+#    #+#             */
/*   Updated: 2019/02/15 21:51:00 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris		*read_tet(char *buffer)
{
	t_tetris	*t;
	char		*t_shape_buff;
	int			i;

	i = 0;
	t_shape_buff = ft_strnew(16);
	t = malloc(sizeof(t_tetris));
	t->t_count = (int)((ft_strlen(buffer) + 1) / 21);
	if (t->t_count < 1 || t->t_count > 26)
		return (NULL);
	t->points = (t_point ***)malloc(sizeof(t_point**) * t->t_count);
	t->tet_i = 0;
	t->grid_size = ft_sqrt(t->t_count * 4);
	t->grid = 0;
	while (((unsigned long)i < ft_strlen(buffer)) && t->tet_i < t->t_count)
	{
		t->points[t->tet_i] = (t_point **)malloc(sizeof(t_point*) * 4);
		get_tet(buffer, t_shape_buff, i);
		if (set_points(t, t_shape_buff) == 0)
			return (NULL);
		i = i + 21;
		t->tet_i++;
	}
	free(t_shape_buff);
	return (t);
}

int				check_tet(t_tetris *t, int connections)
{
	int			x;
	int			y;
	int			p_i;

	while (++t->tet_i < t->t_count)
	{
		connections = 0;
		p_i = -1;
		while (++p_i < 4)
		{
			y = -2;
			while (++y <= 1)
			{
				x = -2;
				while (++x <= 1)
					if (x != y && (x + y) != 0)
						if (s_p(t, t->points[t->tet_i][p_i]->x + x,
						t->points[t->tet_i][p_i]->y + y))
							connections++;
			}
		}
		if (connections < 6)
			return (0);
	}
	return (1);
}

void			get_tet(char *buffer, char *t_shape_buff, int i)
{
	int			nl_c;

	nl_c = 0;
	while (buffer[i] != '\0' && nl_c != 4)
	{
		if (buffer[i] == '\n')
		{
			i++;
			nl_c++;
		}
		else
			*t_shape_buff++ = buffer[i++];
	}
	i++;
}

int				try_put_tet(t_tetris *t, int x, int y)
{
	x--;
	y--;
	while (++(y) < t->grid_size)
	{
		while (++(x) < t->grid_size)
		{
			if (check_points(t, 0, x, y) == 1)
			{
				if (put_on_grid(t, x, y) == 1)
					return (1);
				else
				{
					del_tet(t);
					return (0);
				}
			}
		}
		x = -1;
	}
	return (0);
}

int				del_tet(t_tetris *t)
{
	int			x;
	int			y;

	y = -1;
	while (++y < t->grid_size)
	{
		x = -1;
		while (++x < t->grid_size)
		{
			if (t->grid[x][y] == 'A' + t->tet_i)
				t->grid[x][y] = '.';
		}
	}
	return (1);
}
