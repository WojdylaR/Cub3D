/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_put_color(int r, int g, int b)
{
	return (r * 256 * 256 + g * 256 + b);
}

void	ft_dist(t_player *player)
{
	if (player->side == 1 || player->side == 2)
		P->perpwalldist = (P->mapx - P->pos_x +
			(1 - P->stepx) / 2) / P->raydirx;
	else
		P->perpwalldist = (P->mapy - P->pos_y +
			(1 - P->stepy) / 2) / P->raydiry;
	player->lineheight = (long int)(player->height / player->perpwalldist);
	player->drawstart = -player->lineheight / 2 + player->height / 2;
	if (player->drawstart < 0)
		player->drawstart = 0;
	player->drawend = player->lineheight / 2 + player->height / 2;
	if (player->drawend >= player->y_screen)
		player->drawend = player->y_screen - 1;
}

void	ft_draw_ceilling(t_player *player)
{
	int i;

	i = 0;
	while (i < player->drawstart)
	{
		P->img_data[i * P->x_screen + (int)P->x] =
			ft_put_color(P->c_red, P->c_green, P->c_blue);
		i++;
	}
}

void	ft_draw_text(t_player *player)
{
	player->textnum = player->side;
	if (player->side == 1 || player->side == 2)
		P->wallx = P->pos_y + P->perpwalldist * P->raydiry;
	else
		P->wallx = P->pos_x + P->perpwalldist * player->raydirx;
	player->wallx -= floorf(player->wallx);
	player->textx = (int)(player->wallx * 512);
	if (player->side == 1 && player->raydirx > 0)
		player->textx = 512 - player->textx - 1;
	if (player->side == 2 && player->raydirx < 0)
		player->textx = 512 - player->textx - 1;
	player->step = 1 * 512 / player->lineheight;
	P->texposx = (P->drawstart - P->height / 2 + P->lineheight / 2) * P->step;
	while (player->drawstart < player->drawend)
	{
		player->tex_y = (int)player->texposx;
		player->texposx += player->step;
		P->img_data[P->drawstart++ * P->x_screen + (int)P->x] =
			P->xpm_char[player->textnum][512 * player->tex_y + player->textx];
	}
}

void	ft_draw_ground(t_player *player)
{
	int i;

	i = player->drawend;
	while (i < player->y_screen - 1)
	{
		P->img_data[i * P->x_screen + (int)P->x] =
			ft_put_color(P->g_red, P->g_green, P->g_blue);
		i++;
	}
}
