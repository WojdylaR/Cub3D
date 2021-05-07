/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check_color_gr(t_player *player)
{
	int x;

	x = 0;
	while (ft_isdigit(player->gr[x]) == 0)
		x++;
	while (P->gr[x])
	{
		if (ft_isdigit(P->gr[x]) == 0 && P->gr[x] != ',')
		{
			ft_putstr_fd("bad_color_ground", 1);
			free_all(player);
		}
		x++;
	}
	if (P->g_blue > 255 || P->g_blue < 0 || P->g_green > 255 ||
		P->g_green < 0 || P->g_red > 255 || P->g_red < 0)
	{
		ft_putstr_fd("bad_color_ground", 1);
		free_all(player);
	}
	return (1);
}

int		ft_check_color_ce(t_player *player)
{
	int x;

	x = 0;
	while (ft_isdigit(player->ce[x]) == 0)
		x++;
	while (P->ce[x])
	{
		if (ft_isdigit(P->ce[x]) == 0 && P->ce[x] != ',')
		{
			ft_putstr_fd("bad_color_ceilling", 1);
			free_all(player);
		}
		x++;
	}
	if (P->c_blue > 255 || P->c_blue < 0 || P->c_green > 255 ||
		P->c_green < 0 || P->c_red > 255 || P->c_red < 0)
	{
		ft_putstr_fd("bad_color_ceilling", 1);
		free_all(player);
	}
	return (1);
}

void	ft_put_ce(char *line, t_player *player)
{
	int x;

	x = 0;
	while (ft_isdigit(line[x]) == 0)
		x++;
	player->c_red = ft_atoi(line + x);
	while (ft_isdigit(line[x]) == 1)
		x++;
	player->c_green = ft_atoi(line + x + 1);
	while (ft_isdigit(line[x + 1]) == 1)
		x++;
	x = ft_atoi(line + x + 2);
	player->c_blue = x;
}

void	ft_put_gr(char *line, t_player *player)
{
	int x;

	x = 0;
	while (ft_isdigit(line[x]) == 0)
		x++;
	player->g_red = ft_atoi(line + x);
	while (ft_isdigit(line[x]) == 1)
		x++;
	player->g_green = ft_atoi(line + x + 1);
	while (ft_isdigit(line[x + 1]) == 1)
		x++;
	x = ft_atoi(line + x + 2);
	player->g_blue = x;
}
