/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:41:04 by hirenpat          #+#    #+#             */
/*   Updated: 2019/02/15 21:41:06 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int ac, char **av)
{
	int			fd;
	char		*buffer;
	t_tetris	*t;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		buffer = (fd > 0 ? read_file(fd) : "\0");
		if (check_fillit_file(buffer))
		{
			if ((t = read_tet(buffer)) == NULL)
				return (file_tet(fd, buffer));
			t->tet_i = -1;
			if (check_tet(t, 0) == 0)
				return (fail(fd, t, buffer));
			t->grid = make_grid(t->grid_size);
			if (tetris(t) == 1)
				return (pass(fd, t, buffer));
		}
		return (file_fail(fd));
	}
	return (usage());
}

int				tetris(t_tetris *t)
{
	t->tet_i = 0;
	while (backtrack(t) == 0)
		resize_grid(t);
	return (1);
}
