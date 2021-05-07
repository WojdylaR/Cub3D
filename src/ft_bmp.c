/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_put_screen(t_player *player)
{
	int y;

	y = player->y_screen;
	write(player->bmp_fd, player->h_bmp, 54);
	while (y)
	{
		write(P->bmp_fd, P->img_data + (y * P->x_screen), P->x_screen * 4);
		y--;
	}
	close(player->bmp_fd);
	free_all(player);
}

void	ft_bmp(t_player *player)
{
	ft_memcpy(player->h_bmp, "BM", 2);
	ft_memcpy(player->h_bmp + 2, &player->file_bmp_size, 4);
	ft_memcpy(player->h_bmp + 10, &player->off_bmp, 4);
	ft_memcpy(player->h_bmp + 14, &player->bsize_bmp, 4);
	ft_memcpy(player->h_bmp + 18, &player->x_screen, 4);
	ft_memcpy(player->h_bmp + 22, &player->y_screen, 4);
	ft_memcpy(player->h_bmp + 26, &player->bmp_planes, 4);
	ft_memcpy(player->h_bmp + 28, &player->bpp, 4);
	ft_memcpy(player->h_bmp + 34, &player->size_bmp, 4);
	P->bmp_fd = open("./screen.bmp", O_RDWR | O_CREAT |
		O_TRUNC, S_IRUSR | S_IWUSR);
	ft_put_screen(player);
}

void	ft_init_bpm(t_player *player)
{
	int i;

	i = 0;
	while (i < 54)
		player->h_bmp[i++] = 0;
	player->bpp = 32;
	player->x_screen_bmp =
		((player->x_screen * player->bpp + 31) / 32) * 4;
	player->size_bmp = player->x_screen_bmp * player->y_screen;
	player->bsize_bmp = 40;
	player->off_bmp = 54;
	player->file_bmp_size = 54 + player->size_bmp;
	player->bmp_planes = 1;
	ft_bmp(player);
}
