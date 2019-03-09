/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 22:49:09 by hirenpat          #+#    #+#             */
/*   Updated: 2019/02/15 22:49:11 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char*)malloc(sizeof(char) * len);
	if (!join)
		return (NULL);
	join[len - 1] = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		++i;
	}
	while (i < len)
		join[i++] = s2[j++];
	return (join);
}

char		*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(char) * size + 1);
	if (new == NULL)
		return (NULL);
	while (i <= size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}
