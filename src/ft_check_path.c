/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_xpm(char *str)
{
	int i;

	i = 5;
	if (!(str))
		return (-1);
	while (str[i])
		i++;
	if (str[i - 3] == 'x' && str[i - 2] == 'p' && str[i - 1] == 'm')
		return (1);
	return (-1);
}

int		check_path(char *str)
{
	int fd;

	if ((fd = open(str, 0x0000) < 0))
		return (-1);
	close(fd);
	return (1);
}

int		ft_check_path(t_player *player)
{
	if (check_xpm(player->sp) == -1 || check_path(player->sp) == -1)
		return (-1);
	if (check_xpm(player->we) == -1 || check_path(player->we) == -1)
		return (-1);
	if (check_xpm(player->so) == -1 || check_path(player->so) == -1)
		return (-1);
	if (check_xpm(player->no) == -1 || check_path(player->no) == -1)
		return (-1);
	if (check_xpm(player->ea) == -1 || check_path(player->ea) == -1)
		return (-1);
	return (1);
}
