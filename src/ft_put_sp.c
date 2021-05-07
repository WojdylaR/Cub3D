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

#include "../includes/cub3d.h"

void	ft_sp_yx(t_player *player, int *spriteorder)
{
	P->sp_x = P->x_sp[spriteorder[P->z_sp]] - P->pos_x + 0.5;
	P->sp_y = P->y_sp[spriteorder[P->z_sp]] - P->pos_y + 0.5;
	P->inv = 1 / (P->planex * P->diry - P->dirx * P->planey);
	P->tr_x = P->inv * (P->diry * P->sp_x - P->dirx * P->sp_y);
	P->tr_y = P->inv * (-P->planey * P->sp_x + P->planex * P->sp_y);
	P->sp_x_screen = (int)((P->x_screen / 2) * (1 + P->tr_x / P->tr_y));
	P->sp_height = abs((int)(P->y_screen / P->tr_y));
	P->sp_width = abs((int)(P->y_screen / P->tr_y));
	P->start_y_sp = -P->sp_height / 2 + P->y_screen / 2;
	P->end_y_sp = P->sp_height / 2 + P->y_screen / 2;
	P->start_x_sp = -P->sp_width / 2 + P->sp_x_screen;
	P->end_x_sp = P->sp_width / 2 + P->sp_x_screen;
	if (P->start_y_sp < 0)
		P->start_y_sp = 0;
	if (P->end_y_sp >= P->y_screen)
		P->end_y_sp = P->y_screen - 1;
	if (P->start_x_sp < 0)
		P->start_x_sp = 0;
	if (P->end_x_sp >= P->x_screen)
		P->end_x_sp = P->x_screen;
}

void	ft_draw_sp(t_player *player)
{
	if (P->tr_y > 0 && P->i_sp > 0 && P->i_sp <
		P->x_screen && P->tr_y < P->z_buffer[P->i_sp])
	{
		while (P->sp_s_y < P->end_y_sp)
		{
			P->d_sp = (P->sp_s_y) * 256 -
				P->y_screen * 128 + P->sp_height * 128;
			P->texy_sp = ((P->d_sp * 64) / P->sp_height) / 256;
			if ((64 * P->texy_sp + P->texx_sp) > 64)
				P->color_sp = P->sprite_data[64 * P->texy_sp +
					P->texx_sp];
			else
				P->color_sp = 0;
			if (P->color_sp > 0 && P->color_sp & 0x00FFFFFF)
			{
				P->img_data[P->sp_s_y * P->x_screen + P->i_sp] =
					P->color_sp;
			}
			P->sp_s_y++;
		}
	}
}

void	ft_sp_dist(t_player *player, int *spriteorder)
{
	ft_sp_yx(player, spriteorder);
	P->i_sp = P->start_x_sp;
	while (P->i_sp < P->end_x_sp)
	{
		P->texx_sp = (int)(256 * (P->i_sp -
			(-P->sp_width / 2 + P->sp_x_screen)) * 64 / P->sp_width) / 256;
		P->sp_s_y = P->start_y_sp;
		ft_draw_sp(player);
		P->i_sp++;
	}
	P->z_sp++;
}

void	ft_spritee(t_player *player)
{
	int		spriteorder[player->sp_nb];
	float	sprite_dist[player->sp_nb];

	P->i_sp = 0;
	P->z_sp = 0;
	while (P->i_sp < P->sp_nb)
	{
		spriteorder[P->i_sp] = P->i_sp;
		sprite_dist[P->i_sp] = pow(P->pos_x - P->x_sp[P->i_sp], 2) +
			pow(P->pos_y - P->y_sp[P->i_sp], 2);
		P->i_sp++;
	}
	ft_trii(spriteorder, sprite_dist, player);
	while (P->z_sp < P->sp_nb)
		ft_sp_dist(player, spriteorder);
	free(P->x_sp);
	free(P->y_sp);
}
