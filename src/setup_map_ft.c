/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_fill_map(char *line, int x, int i, t_player *player)
{
	char *temp;

	temp = ft_strdup(player->m);
	free(player->m);
	player->m = ft_strjoin(temp, line);
	free(temp);
	temp = ft_strdup(player->m);
	free(player->m);
	player->m = ft_strjoin(temp, "\n");
	free(temp);
}

int		fill_arg(char *line, int x, int i, t_player *player)
{
	line[x] == 'N' && line[x + 1] == 'O' ? P->no = ft_strdup(line + i) : 0;
	if (line[x] == 'S' && line[x + 1] == 'O')
		P->so = ft_strdup(line + i);
	line[x] == 'E' && line[x + 1] == 'A' ? P->ea = ft_strdup(line + i) : 0;
	line[x] == 'W' && line[x + 1] == 'E' ? P->we = ft_strdup(line + i) : 0;
	if (line[x] == 'S' && line[x + 1] == ' ')
		P->sp = ft_strdup(line + i);
	line[x] == 'C' && line[x + 1] == ' ' ? P->ce = ft_strdup(line + i) : 0;
	line[x] == 'F' && line[x + 1] == ' ' ? P->gr = ft_strdup(line + i) : 0;
	line[x] == 'R' && line[x + 1] == ' ' ? ft_fill_resolution(line, P) : 0;
	line[x] == '1' || line[x] == '0' ||
		line[x] == '2' ? ft_fill_map(line, x, i, player) : 0;
	line[x] == 'C' && line[x + 1] == ' ' ? ft_put_ce(line, player) : 0;
	line[x] == 'F' && line[x + 1] == ' ' ? ft_put_gr(line, player) : 0;
	if (((line[x] == '\0') || (line[x] == '\n') || (line[x] == '1' ||
		line[x] == '0' || line[x] == '2') || (line[x] == 'R' &&
		line[x + 1] == ' ') || (line[x] == 'C' && line[x + 1] == ' ') ||
		(line[x] == 'F' && line[x + 1] == ' ') || (line[x] == 'S' &&
		line[x + 1] == ' ') || (line[x] == 'W' && line[x + 1] == 'E') ||
		(line[x] == 'E' && line[x + 1] == 'A') || (line[x] == 'N' &&
		line[x + 1] == 'O') || (line[x] == 'S' && line[x + 1]) ||
		(line[x] == 'S' && line[x + 1] == 'O')))
		return (1);
	ft_putstr_fd("bad_path", 1);
	free_all(player);
}

void	fill_struct_map(char *line, t_player *player)
{
	int x;
	int i;
	int r;

	x = 0;
	i = 0;
	while (line[x] == ' ')
		x++;
	while (line[x + i + 2] == ' ')
		i++;
	fill_arg(line, x, x + i + 2, player);
}

void	ft_bmp_arg(t_player *player, int argc, char **argv)
{
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
		player->bmp = 1;
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) != 0 ||
		check_path(argv[1]) == -1)
	{
		ft_putstr_fd("mauvaises argument !", 1);
		free_all(player);
	}
	if (argc == 2 && check_path(argv[1]) == -1)
	{
		ft_putstr_fd("mauvaise argument !", 1);
		free_all(player);
	}
	if (argc == 1 || argc > 3)
	{
		ft_putstr_fd("mauvaise argument !", 1);
		free_all(player);
	}
}

int		setup_map(t_player *player, int argc, char **argv)
{
	char	*line;
	int		fd;
	int		x;
	int		r;

	x = 0;
	ft_bmp_arg(player, argc, argv);
	player->m = ft_strdup("");
	fd = open(argv[1], O_RDONLY);
	r = get_next_line(fd, &line);
	player->ms = 0.06f;
	while (r)
	{
		fill_struct_map(line, player);
		free(line);
		r = get_next_line(fd, &line);
	}
	fill_struct_map(line, player);
	ft_get_address(player);
	player->tab_map = ft_split(player->m, '\n');
	free(line);
	if (check_error(player) != 1)
		return (-1);
	ft_get_data(player);
	return (1);
}
