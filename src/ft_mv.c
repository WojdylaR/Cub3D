/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mv_right(t_player *player)
{
	float x;
	float y;

	x = player->pos_x - player->diry * player->ms / 2;
	y = player->pos_y;
	if (player->tab_map[(int)(y)][(int)x] == '0' ||
		player->tab_map[(int)(y)][(int)x] == player->pos_start)
		player->pos_x -= player->diry * player->ms / 2;
	y = player->pos_y + player->dirx * player->ms / 2;
	x = player->pos_x;
	if (player->tab_map[(int)(y)][(int)x] == '0' ||
		player->tab_map[(int)(y)][(int)x] == player->pos_start)
		player->pos_y += player->dirx * player->ms / 2;
}

void	ft_mv_left(t_player *player)
{
	float x;
	float y;

	x = player->pos_x + player->diry * player->ms / 2;
	y = player->pos_y;
	if (player->tab_map[(int)(y)][(int)x] == '0' ||
		player->tab_map[(int)(y)][(int)x] == player->pos_start)
		player->pos_x += player->diry * player->ms / 2;
	y = player->pos_y - player->dirx * player->ms / 2;
	x = player->pos_x;
	if (player->tab_map[(int)(y)][(int)x] == '0' ||
		player->tab_map[(int)(y)][(int)x] == player->pos_start)
		player->pos_y -= player->dirx * player->ms / 2;
}

void	ft_up(t_player *player)
{
	int x;
	int y;

	x = (int)(player->pos_x + player->dirx * player->ms);
	y = (int)(player->pos_y);
	if (player->tab_map[y][x] == '0' ||
		player->tab_map[y][x] == player->pos_start)
		player->pos_x += player->dirx * player->ms;
	x = (int)player->pos_x;
	y = (int)(player->pos_y + player->diry * 0.06);
	if (player->tab_map[y][x] == '0' ||
		player->tab_map[y][x] == player->pos_start)
		player->pos_y += player->diry * player->ms;
}

void	ft_down(t_player *player)
{
	int x;
	int y;

	x = (int)(player->pos_x - player->dirx * player->ms);
	y = (int)(player->pos_y);
	if (player->tab_map[y][x] == '0' ||
		player->tab_map[y][x] == player->pos_start)
		player->pos_x -= player->dirx * player->ms;
	x = (int)player->pos_x;
	y = (int)(player->pos_y - player->diry * 0.06);
	if (player->tab_map[y][x] == '0' ||
		player->tab_map[y][x] == player->pos_start)
		player->pos_y -= player->diry * player->ms;
}

int		ft_move(t_player *player)
{
	if (player->down)
		ft_down(player);
	if (player->mv_right)
		ft_mv_right(player);
	if (player->mv_left)
		ft_mv_left(player);
	if (player->right)
		ft_right(player);
	if (player->left)
		ft_left(player);
	if (player->up)
		ft_up(player);
}
