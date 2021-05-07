/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_char(t_player *player)
{
	int x;
	int i;

	i = 0;
	x = 0;
	while (player->m[x])
	{
		if (!(ft_strrchr("012NSEW \n", player->m[x])))
			return (-1);
		if (ft_strrchr("NSEW", player->m[x]))
			i++;
		x++;
	}
	if (i != 1)
		return (-1);
	return (1);
}

int		check_map(t_player *player)
{
	int x;
	int i;
	int y;

	player->nb_l = 0;
	x = 0;
	i = 0;
	while (player->m[x])
	{
		if (player->m[x] == '\n')
			player->nb_l++;
		x++;
	}
	if (player->nb_l < 3)
	{
		ft_putstr_fd("erreur de map", 1);
		free_all(player);
	}
	return (1);
}

int		ft_check_cote(char **tab, int i, int x, char c)
{
	if (!(tab[i + 1][x]) || (tab[i + 1][x] == ' '))
		return (-1);
	if (!(tab[i - 1][x]) || (tab[i - 1][x] == ' '))
		return (-1);
	if (!(tab[i][x + 1]) || (tab[i][x + 1] == ' '))
		return (-1);
	if (!(tab[i][x - 1]) || (tab[i][x - 1] == ' '))
		return (-1);
	return (1);
}

int		ft_check_map_close(t_player *player)
{
	int i;
	int x;

	x = 0;
	i = 1;
	while (player->tab_map[0][x])
		if (player->tab_map[0][x++] == '0')
			return (-1);
	while (player->nb_l > i + 1)
	{
		x = 0;
		while (player->tab_map[i][x])
		{
			if (player->tab_map[i][x] == '0' &&
				ft_check_cote(player->tab_map, i, x, player->pos_start) == -1)
				return (-1);
			x++;
		}
		i++;
	}
	x = 0;
	while (player->tab_map[i][x])
		if (player->tab_map[i][x++] == '0')
			return (-1);
	return (1);
}

int		check_error(t_player *player)
{
	if (check_char(player) == -1)
		return (-1);
	if (check_map(player) == -1)
		return (-1);
	if (ft_check_path(player) == -1)
	{
		ft_putstr_fd("bad_path", 1);
		free_all(player);
	}
	if (ft_check_map_close(player) == -1)
		return (-1);
	if (ft_check_color_gr(player) == -1)
		return (-1);
	if (ft_check_color_ce(player) == -1)
		return (-1);
	return (1);
}
