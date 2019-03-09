/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:38:58 by hirenpat          #+#    #+#             */
/*   Updated: 2019/02/15 21:39:04 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		backtrack(t_tetris *t)
{
	int x;
	int y;

	if (t->tet_i >= t->t_count)
		return (1);
	y = -1;
	while (++y < t->grid_size)
	{
		x = -1;
		while (++x < t->grid_size)
		{
			if (try_put_tet(t, x, y))
			{
				t->tet_i++;
				if (backtrack(t))
					return (1);
				else
				{
					t->tet_i--;
					del_tet(t);
				}
			}
		}
	}
	return (0);
}
