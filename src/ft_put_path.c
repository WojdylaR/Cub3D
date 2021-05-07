/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_get_data(t_player *player)
{
	int bpp;
	int x;
	int e;
	int xs;
	int sprite_endian;

	xs = 64;
	sprite_endian = 1;
	player->size_line = player->x_screen * 4;
	x = 512;
	e = 0;
	P->sprite_data =
		(int *)mlx_get_data_addr(P->sprite_adrs, &bpp, &xs, &sprite_endian);
	P->xpm_char[0] = (int *)mlx_get_data_addr(P->XA[0], &bpp, &x, &e);
	P->xpm_char[1] = (int *)mlx_get_data_addr(P->XA[1], &bpp, &x, &e);
	P->xpm_char[2] = (int *)mlx_get_data_addr(P->XA[2], &bpp, &x, &e);
	P->xpm_char[3] = (int *)mlx_get_data_addr(P->XA[3], &bpp, &x, &e);
	P->xpm_char[4] = (int *)mlx_get_data_addr(P->XA[4], &bpp, &x, &e);
	P->xpm_char[5] = (int *)mlx_get_data_addr(P->XA[5], &bpp, &x, &e);
	P->img_adress = mlx_new_image(P->mlx_ptr, P->x_screen, player->y_screen);
	P->img_data =
		(int *)mlx_get_data_addr(P->img_adress, &P->size_line, &P->y_img, &e);
}

void	ft_get_address(t_player *player)
{
	int x;
	int xs;

	xs = 64;
	x = 512;
	P->mlx_ptr = mlx_init();
	P->sprite_adrs = mlx_xpm_file_to_image(P->mlx_ptr, player->sp, &xs, &xs);
	P->XA[0] = mlx_xpm_file_to_image(P->mlx_ptr, P->ea, &x, &x);
	P->XA[1] = mlx_xpm_file_to_image(P->mlx_ptr, P->we, &x, &x);
	P->XA[2] = mlx_xpm_file_to_image(P->mlx_ptr, P->ea, &x, &x);
	P->XA[3] = mlx_xpm_file_to_image(P->mlx_ptr, P->so, &x, &x);
	P->XA[4] = mlx_xpm_file_to_image(P->mlx_ptr, P->no, &x, &x);
	P->XA[5] = mlx_xpm_file_to_image(P->mlx_ptr, P->no, &x, &x);
	P->textnum = 0;
}

int		ft_check_res(char *line, t_player *player)
{
	int x;
	int n;

	x = 0;
	n = 0;
	while (line[x] != 'R')
		x++;
	x++;
	while (line[x])
	{
		n++;
		while (line[x] == ' ')
			x++;
		if (ft_isdigit(line[x]) == 0 && line[x] != '\0')
		{
			return (-1);
		}
		while (ft_isdigit(line[x]) == 1)
			x++;
	}
	return (n);
}

void	ft_fill_resolution(char *line, t_player *player)
{
	int x;

	x = 0;
	while (ft_isdigit(line[x]) == 0)
		x++;
	player->x_screen = ft_atoi(line + x);
	while (ft_isdigit(line[x]) == 1)
		x++;
	while ((line[x]) == ' ')
		x++;
	player->y_screen = ft_atoi(line + x);
	while (ft_isdigit(line[x]) == 1)
		x++;
	if (ft_check_res(line, player) != 2 ||
		P->x_screen == 0 || P->y_screen == 0)
	{
		ft_putstr_fd("bad_res", 1);
		free_all(player);
	}
	if (player->x_screen > 1920)
		player->x_screen = 1920;
	if (player->y_screen > 1080)
		player->y_screen = 1080;
}
