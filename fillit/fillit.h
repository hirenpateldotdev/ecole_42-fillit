/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:51:17 by hirenpat          #+#    #+#             */
/*   Updated: 2019/02/15 21:51:21 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_tetris
{
	t_point		***points;
	char		**grid;
	int			t_count;
	int			grid_size;
	int			tet_i;
}				t_tetris;

int				free_grid(t_tetris *t);
int				free_points(t_tetris *t);
int				free_world(t_tetris *t, char *buffer);
void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnew(size_t size);
size_t			ft_strlen(const char *s);
int				ft_sqrt(int nb);
int				pass(int fd, t_tetris *t, char *buffer);
int				fail(int fd, t_tetris *t, char *buffer);
int				file_tet(int fd, char *buffer);
int				file_fail(int fd);
int				usage(void);
int				main(int ac, char **av);
int				tetris(t_tetris *t);
char			*read_file(int fd);
int				check_fillit_file(char *buffer);
t_tetris		*read_tet(char *buffer);
int				check_tet(t_tetris *t, int connections);
void			get_tet(char *buffer, char *t_shape_buff, int i);
int				try_put_tet(t_tetris *t, int x, int y);
int				del_tet(t_tetris *t);
int				set_points(t_tetris *tetris, char *t_shape_buff);
int				s_p(t_tetris *t, int x, int y);
int				check_points(t_tetris *t, int p_i, int x, int y);
void			set_p(t_point *p, int x, int y);
char			**make_grid(int size);
void			resize_grid(t_tetris *t);
void			print_grid(char **str, int size);
int				put_on_grid(t_tetris *t, int x, int y);
int				backtrack(t_tetris *t);

#endif
