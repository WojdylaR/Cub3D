/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_wall_hit(t_player *player)
{
	if (player->side == 1)
	{
		if (player->mapx < player->pos_x)
			player->side = 2;
	}
	else
	{
		if (player->mapy > player->pos_y)
		{
			player->side = 4;
		}
	}
}

void	ft_init_ray(t_player *player)
{
	player->camerax = 2 * player->x / (double)player->x_screen - 1;
	player->raydirx = player->dirx + player->planex * player->camerax;
	player->raydiry = player->diry + player->planey * player->camerax;
	player->mapx = (int)player->pos_x;
	player->mapy = (int)player->pos_y;
	player->deltadistx = fabsf(1 / player->raydirx);
	player->deltadisty = fabsf(1 / player->raydiry);
	player->hit = 0;
}

void	ft_init_sidedist(t_player *player)
{
	if (player->raydirx < 0)
	{
		player->stepx = -1;
		P->sidedistx = (P->pos_x - P->mapx) * P->deltadistx;
	}
	else
	{
		player->stepx = 1;
		P->sidedistx = (P->mapx + 1.0 - P->pos_x) * P->deltadistx;
	}
	if (player->raydiry < 0)
	{
		player->stepy = -1;
		P->sidedisty = (P->pos_y - P->mapy) * P->deltadisty;
	}
	else
	{
		player->stepy = 1;
		P->sidedisty = (P->mapy + 1.0 - P->pos_y) * P->deltadisty;
	}
}

void	ft_hit(t_player *player)
{
	while (player->hit == 0)
	{
		if (player->sidedistx < player->sidedisty)
		{
			player->sidedistx += player->deltadistx;
			player->mapx += player->stepx;
			player->side = 1;
		}
		else
		{
			player->sidedisty += player->deltadisty;
			player->mapy += player->stepy;
			player->side = 3;
		}
		if (player->tab_map[player->mapy][player->mapx] == '1')
			player->hit = 1;
	}
	ft_wall_hit(player);
}

int		ft_loop(t_player *player)
{
	ft_init_ray(player);
	ft_init_sidedist(player);
	ft_hit(player);
	ft_dist(player);
	ft_draw_ceilling(player);
	ft_draw_text(player);
	ft_draw_ground(player);
	player->z_buffer[(int)player->x] = player->perpwalldist;
}
