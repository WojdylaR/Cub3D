/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwojdyla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:37:39 by rwojdyla          #+#    #+#             */
/*   Updated: 2020/03/13 01:41:08 by rwojdyla         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

# define P player
# define XA xpm_addresse

typedef struct		s_player
{
	float			pos_x;
	float			pos_y;
	float			dirx;
	float			diry;
	float			old_dirx;
	char			pos_start;
	float			planex;
	float			planey;
	int				hit;
	int				side;
	int				mapx;
	int				mapy;
	float			sidedistx;
	float			sidedisty;
	float			camerax;
	float			old_planex;
	float			raydirx;
	float			raydiry;
	float			deltadistx;
	float			deltadisty;
	float			perpwalldist;
	int				stepx;
	int				stepy;
	float			lineheight;
	int				drawstart;
	int				drawend;
	float			wallx;
	int				textx;
	float			step;
	float			texposx;
	int				texposy;
	int				tex_y;
	int				x;
	int				left;
	int				right;
	int				down;
	int				mv_right;
	int				mv_left;
	int				up;
	float			ms;
	int				x_screen;
	int				y_screen;
	int				height;
	int				nb_l;
	int				l_len;
	int				x_img;
	int				y_img;
	char			*in;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*sp;
	char			*ce;
	char			*gr;
	int				c_red;
	int				c_blue;
	int				c_green;
	int				g_red;
	int				g_blue;
	int				g_green;
	char			*m;
	char			**tab_map;
	int				size_line;
	void			*xpm_addresse[6];
	int				*xpm_char[6];
	int				textnum;
	void			*img_adress;
	int				*img_data;
	void			*sprite_adrs;
	int				*sprite_data;
	int				sp_nb;
	int				*x_sp;
	int				*y_sp;
	int				i_sp;
	int				z_sp;
	int				d_sp;
	int				start_y_sp;
	int				end_y_sp;
	int				start_x_sp;
	int				end_x_sp;
	int				texx_sp;
	int				texy_sp;
	int				sp_width;
	int				sp_s_y;
	float			sp_x;
	float			sp_y;
	float			inv;
	float			tr_y;
	float			tr_x;
	int				sp_x_screen;
	int				sp_height;
	float			*z_buffer;
	unsigned int	color_sp;
	void			*mlx_ptr;
	void			*win_ptr;
	int				bmp;
	int				bmp_fd;
	unsigned char	h_bmp[54];
	int				bpp;
	int				x_screen_bmp;
	unsigned int	size_bmp;
	unsigned int	bsize_bmp;
	unsigned int	off_bmp;
	unsigned int	file_bmp_size;
	unsigned int	bmp_planes;
}					t_player;

int					ft_check_path(t_player *player);
int					check_error(t_player *player);
int					setup_map(t_player *map, int argc, char **argv);
int					ft_init_player(t_player *player);
int					ft_loop(t_player *player);
void				ft_get_data(t_player *player);
void				ft_get_address(t_player *player);
void				ft_fill_resolution(char *line, t_player *player);
void				ft_put_ce(char *line, t_player *player);
void				ft_put_gr(char *line, t_player *player);
void				ft_dist(t_player *player);
void				ft_draw_ceilling(t_player *player);
void				ft_draw_text(t_player *player);
void				ft_draw_ground(t_player *player);
void				ft_left(t_player *player);
void				ft_right(t_player *player);
int					ft_move(t_player *player);
void				ft_spritee(t_player *player);
void				ft_trii(int spriteorder[],
	float sprite_dist[], t_player *player);
void				ft_how_many_sprite(t_player *player);
int					ft_malloc_x_y_sprite(t_player *player);
void				ft_put_x_y_sprite(t_player *player);
int					ft_key_press(int key, t_player *player);
int					ft_key_release(int key, t_player *player);
int					free_all(t_player *player);
int					ft_key_release(int key, t_player *player);
int					ft_key_press(int key, t_player *player);
void				ft_init_bpm(t_player *player);
int					check_path(char *str);
int					ft_check_color_gr(t_player *player);
int					ft_check_color_ce(t_player *player);

#endif
