/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_path(t_player *player)
{
	if (player->no)
		free(player->no);
	if (player->in)
		free(player->in);
	if (player->so)
		free(player->so);
	if (player->ea)
		free(player->ea);
	if (player->we)
		free(player->we);
	if (player->sp)
		free(player->sp);
}

void	ft_free_img_adrs(t_player *player)
{
	if (player->img_adress)
		mlx_destroy_image(player->mlx_ptr, player->img_adress);
	if (player->xpm_addresse[4])
		mlx_destroy_image(player->mlx_ptr, player->xpm_addresse[4]);
	if (player->xpm_addresse[3])
		mlx_destroy_image(player->mlx_ptr, player->xpm_addresse[3]);
	if (player->xpm_addresse[2])
		mlx_destroy_image(player->mlx_ptr, player->xpm_addresse[2]);
	if (player->xpm_addresse[1])
		mlx_destroy_image(player->mlx_ptr, player->xpm_addresse[1]);
	if (player->xpm_addresse[0])
		mlx_destroy_image(player->mlx_ptr, player->xpm_addresse[0]);
}

void	ft_free_map(t_player *player)
{
	int i;

	i = 0;
	if (player->m)
		free(player->m);
	if (player->tab_map)
	{
		while (player->tab_map[i])
			i++;
		while (i)
			free(player->tab_map[i--]);
		free(player->tab_map[i]);
		free(player->tab_map);
	}
}

void	ft_free_some_var(t_player *player)
{
	if (player->ce)
		free(player->ce);
	if (player->gr)
		free(player->gr);
}

int		free_all(t_player *player)
{
	ft_free_path(player);
	ft_free_img_adrs(player);
	ft_free_map(player);
	free(player->mlx_ptr);
	ft_free_some_var(player);
	exit(EXIT_SUCCESS);
	return (0);
}
