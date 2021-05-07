/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_left(t_player *player)
{
	P->old_dirx = P->dirx;
	P->dirx = P->dirx * cos(-P->ms) - P->diry * sin(-P->ms);
	P->diry = P->old_dirx * sin(-P->ms) + P->diry * cos(-P->ms);
	P->old_planex = P->planex;
	P->planex = P->planex * cos(-P->ms) - P->planey * sin(-P->ms);
	P->planey = P->old_planex * sin(-P->ms) + P->planey * cos(-P->ms);
}

void	ft_right(t_player *player)
{
	P->old_dirx = P->dirx;
	P->dirx = P->dirx * cos(P->ms) - P->diry * sin(P->ms);
	P->diry = P->old_dirx * sin(P->ms) + P->diry * cos(P->ms);
	P->old_planex = P->planex;
	P->planex = P->planex * cos(P->ms) - P->planey * sin(P->ms);
	P->planey = P->old_planex * sin(P->ms) + P->planey * cos(P->ms);
}
