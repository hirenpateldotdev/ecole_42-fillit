/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:39:12 by hirenpat          #+#    #+#             */
/*   Updated: 2019/02/15 21:39:13 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	pass(int fd, t_tetris *t, char *buffer)
{
	close(fd);
	print_grid(t->grid, t->grid_size);
	free_world(t, buffer);
	return (1);
}

int	fail(int fd, t_tetris *t, char *buffer)
{
	close(fd);
	ft_putstr("error\n");
	free_world(t, buffer);
	return (0);
}

int	file_tet(int fd, char *buffer)
{
	close(fd);
	free(buffer);
	ft_putstr("error\n");
	return (0);
}

int	file_fail(int fd)
{
	close(fd);
	ft_putstr("error\n");
	return (0);
}

int	usage(void)
{
	ft_putstr("usage: ./fillit input_file\n");
	return (0);
}
