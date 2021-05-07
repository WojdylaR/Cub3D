/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sp.c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_error(char **line, int fd, int r)
{
	if (line == NULL || fd < 0 || r < 0)
		return (-1);
	return (0);
}

static	int		set_up(char **line, char t[], int r, int fd)
{
	*line = ft_strdup_gnl("");
	t[BUFFER_SIZE] = 0;
	if (!(r))
		r = read(fd, t, BUFFER_SIZE);
	return (r);
}

char			*get_line(char **line, char *t, int i)
{
	char	*temp;
	char	*dst;

	temp = ft_substr_gnl(t, 0, i);
	dst = ft_strjoin_gnl(*line, temp);
	free(temp);
	ft_strlcpy_gnl(t, ft_substr_gnl(t, i + 1, BUFFER_SIZE));
	return (dst);
}

int				get_next_line(int fd, char **line)
{
	static	char	t[BUFFER_SIZE + 1];
	int				i;
	static	int		r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	r = set_up(line, t, r, fd);
	while (r > 0)
	{
		i = 0;
		while (t[i] && t[i] != '\n')
			i++;
		if (t[i] == '\n')
		{
			*line = get_line(line, t, i);
			return (1);
		}
		*line = ft_strjoin_gnl(*line, t);
		i = 0;
		while (i < BUFFER_SIZE)
			t[i++] = 0;
		r = read(fd, t, BUFFER_SIZE);
	}
	return (check_error(line, fd, r));
}
