/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_key_press(int key, t_player *player)
{
	if (key == 97)
		player->mv_left = 1;
	if (key == 100)
		player->mv_right = 1;
	if (key == 115 || key == 65364)
		player->down = 1;
	if (key == 65363)
		player->right = 1;
	if (key == 65361)
		player->left = 1;
	if (key == 119 || key == 65362)
		player->up = 1;
	return (0);
}

int		ft_key_release(int key, t_player *player)
{
	if (key == 97)
		player->mv_left = 0;
	if (key == 100)
		player->mv_right = 0;
	if (key == 115 || key == 65364)
		player->down = 0;
	if (key == 65363)
		player->right = 0;
	if (key == 65361)
		player->left = 0;
	if (key == 119 || key == 65362)
		player->up = 0;
	if (key == 65307)
		free_all(player);
	return (0);
}
