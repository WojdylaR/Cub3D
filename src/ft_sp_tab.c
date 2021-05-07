/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_tab.c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sj_tri(float tab[], int tab2[], int size)
{
	int		i;
	float	temp;
	int		temp2;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i + 1] < tab[i])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			temp2 = tab2[i];
			tab2[i] = tab2[i + 1];
			tab2[i + 1] = temp2;
			i = -1;
		}
		i++;
	}
}

void	ft_trii(int spriteorder[], float sprite_dist[], t_player *player)
{
	float		spritex[P->sp_nb];
	int			spritey[P->sp_nb];
	int			i;

	i = 0;
	while (i < P->sp_nb)
	{
		spritex[i] = sprite_dist[i];
		spritey[i] = spriteorder[i];
		i++;
	}
	sj_tri(spritex, spritey, i);
	i = 0;
	while (i < P->sp_nb)
	{
		sprite_dist[i] = spritex[P->sp_nb - i - 1];
		spriteorder[i] = spritey[P->sp_nb - i - 1];
		i++;
	}
}

void	ft_how_many_sprite(t_player *player)
{
	int i;
	int y;

	y = 0;
	i = 0;
	while (player->m[y])
	{
		if (player->m[y] == '2')
			i++;
		y++;
	}
	player->sp_nb = i;
}

int		ft_malloc_x_y_sprite(t_player *player)
{
	if (!(player->x_sp = malloc(sizeof(int) * player->sp_nb)))
		return (-1);
	if (!(player->y_sp = malloc(sizeof(int) * player->sp_nb)))
		return (-1);
	return (1);
}

void	ft_put_x_y_sprite(t_player *player)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (player->tab_map[y])
	{
		while (player->tab_map[y][x])
		{
			if (player->tab_map[y][x] == '2')
			{
				player->x_sp[i] = x;
				player->y_sp[i] = y;
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
