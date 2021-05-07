/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*pos_player(t_player *player)
{
	int x;

	x = 0;
	player->pos_x = 0.5;
	player->pos_y = 0.5;
	while (ft_strchr("NSEW", player->m[x]) == 0)
	{
		if (player->m[x++] == '\n')
		{
			player->pos_y++;
			player->pos_x = -0.5;
		}
		player->pos_x++;
	}
	player->pos_start = player->m[x];
}

void	*dir_player(t_player *player)
{
	float rot;

	rot = 0;
	player->dirx = -1;
	player->planey = -0.66;
	player->pos_start == 'N' ? rot = 4.71 : 0;
	player->pos_start == 'S' ? rot = 1.58 : 0;
	player->pos_start == 'E' ? rot = 3.14 : 0;
	player->old_dirx = player->dirx;
	player->dirx = player->dirx * cos(-rot) - player->diry * sin(-rot);
	player->diry = player->old_dirx * sin(-rot) + player->diry * cos(-rot);
	player->old_planex = player->planex;
	player->planex = player->planex * cos(-rot) - player->planey * sin(-rot);
	player->planey = player->old_planex * sin(-rot) + P->planey * cos(-rot);
}

int		ft_init_player(t_player *player)
{
	pos_player(player);
	dir_player(player);
	return (0);
}
