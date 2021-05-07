/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_sprite(t_player *player)
{
	ft_how_many_sprite(player);
	ft_malloc_x_y_sprite(player);
	ft_put_x_y_sprite(player);
	ft_spritee(player);
}

int		ft_raycasting(t_player *player)
{
	player->x = 0;
	if (!(player->z_buffer = malloc(sizeof(float) * (player->x_screen))))
		return (0);
	while (player->x < player->x_screen)
	{
		ft_loop(player);
		player->x++;
	}
	ft_sprite(player);
	ft_move(player);
	free(player->z_buffer);
	if (player->bmp == 1)
		ft_init_bpm(player);
	mlx_put_image_to_window(P->mlx_ptr, P->win_ptr, P->img_adress, 0, 0);
	return (1);
}

void	ft_new_window(t_player *player)
{
	P->win_ptr = mlx_new_window(P->mlx_ptr, P->x_screen, P->y_screen, "Cub3d");
	mlx_loop_hook(player->mlx_ptr, ft_raycasting, player);
	mlx_hook(player->win_ptr, 2, 1L << 0, ft_key_press, player);
	mlx_hook(player->win_ptr, 3, 2, ft_key_release, player);
	mlx_hook(player->win_ptr, 33, 1L >> 17, free_all, player);
	mlx_loop(player->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_player *player;

	if (!(player = malloc(sizeof(t_player))))
		return (0);
	if (setup_map(player, argc, argv) != 1)
	{
		ft_putstr_fd("Erreur de map !", 1);
		free_all(player);
		return (0);
	}
	player->height = player->y_screen;
	ft_init_player(player);
	ft_new_window(player);
	return (0);
}
