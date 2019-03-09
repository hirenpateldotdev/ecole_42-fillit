/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:39:36 by hirenpat          #+#    #+#             */
/*   Updated: 2019/02/15 21:39:38 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*read_file(int fd)
{
	int		r;
	char	buff[2];
	char	*temp_buffer;
	char	*buffer;

	buffer = ft_strnew(1);
	while ((r = read(fd, buff, 1)) > 0)
	{
		buff[r] = '\0';
		temp_buffer = buffer;
		buffer = ft_strjoin(buffer, buff);
		free(temp_buffer);
	}
	return (buffer);
}

int			check_fillit_file(char *buffer)
{
	int	nl_c;
	int	c_c;
	int	i;

	i = 0;
	nl_c = 0;
	c_c = 0;
	if (((ft_strlen(buffer) + 1) % 21) != 0)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			nl_c++;
			if ((c_c != 4 && nl_c != 5) || (nl_c == 5 && c_c != 0) ||
			(nl_c == 5 && buffer[i + 1] == '\0'))
				return (0);
			nl_c = (nl_c == 5 ? 0 : nl_c);
			c_c = 0;
		}
		else
			c_c++;
		i++;
	}
	return (1);
}
