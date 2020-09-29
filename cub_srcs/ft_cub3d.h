/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:48:23 by ninieddu          #+#    #+#             */
/*   Updated: 2020/09/29 14:44:24 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct		s_bpm
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_bpm;

typedef struct		s_bpm2
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bpm2;

typedef union
{
	int				color;
	char			argb[3];
}					t_color;

typedef struct		s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_sprites
{
	double		x;
	double		y;
}					t_sprites;

typedef	struct		s_cub3d
{
	int				arg_r;
	int				arg_count;
	int				tracked;
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;
	char			*north;
	int				verif_no;
	char			*south;
	int				verif_so;
	char			*east;
	int				verif_ea;
	char			*west;
	int				verif_we;
	char			*sprite;
	int				verif_sp;
	int				key;
	char			**tab_color;
	int				color_floor;
	int				color_ceiling;
	char			**map;
	char			*tmp_map;
	int				map_spawn;
	int				color;
	int				fd;
	char			*map_path;
	char			dir_player;
	int				verif_c;
	int				verif_f;
	int				hit;
	int				skip;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			olddirx;
	double			olddiry;
	double			planex;
	double			planey;
	double			oldplanex;
	double			oldplaney;
	double			camerax;
	double			raydiry;
	double			raydirx;
	int				stepy;
	int				stepx;
	double			sidedistx;
	double			sidedisty;
	int				mapx;
	int				mapy;
	double			deltadistx;
	double			deltadisty;
	int				side;
	double			perspwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			movespeed;
	double			rotspeed;
	int				left_arrow;
	int				right_arrow;
	int				press_a;
	int				press_d;
	int				press_s;
	int				press_w;
	int				press_shift;
	int				x;
	int				bits_per_pixel;
	int				endian;
	int				size_line;
	int				tex_num;
	int				tex_x;
	int				tex_y;
	int				tex_pos;
	int				no_width;
	int				no_height;
	int				so_width;
	int				so_height;
	int				we_width;
	int				we_height;
	int				ea_width;
	int				ea_height;
	int				sp_width;
	int				sp_height;
	int				sp_w;
	int				sp_h;
	int				drawstartx;
	int				drawendx;
	int				drawstarty;
	int				drawendy;
	int				sp_screen;
	double			transx;
	double			transy;
	double			inv_det;
	double			sp_x;
	double			sp_y;
	int				sp_nbr;
	int				*sp_order;
	double			*sp_dist;
	int				calc;
	void			*img_ptr;
	void			*img_no_ptr;
	void			*img_so_ptr;
	void			*img_we_ptr;
	void			*img_ea_ptr;
	void			*sprite_ptr;
	int				*img_data;
	int				*data_no;
	int				*data_so;
	int				*data_we;
	int				*data_ea;
	int				*data_sprite;
	double			tex_width;
	double			tex_height;
	double			*no_ghost_sprite;
	double			wallx;
	double			texpos;
	double			step;
	int				screenshot;
	int				map_startx;
	int				map_starty;
	int				width_check;
	int				height_check;
	int				maplinecount;
	int				check_color;
	int				z;
}					t_cub3d;

void				ft_map(t_cub3d *game, int ret, char *line);
int					ft_check_map(t_cub3d *game, char *line);
int					ft_check_is_map_line(t_cub3d *game, char *line);
void				ft_check_map_error(t_cub3d *game, int i, int j);
int					ft_key_input(int key, t_cub3d *game);
void				ft_raycasting(t_cub3d *game);
void				ft_raycasting_bonus(t_cub3d *game);
int					ft_key_move(t_cub3d *game);
int					ft_key_release(int key, t_cub3d *game);
int					ft_exit(t_cub3d *game, int x);
void				ft_texture(t_cub3d *game);
void				ft_draw_floor_ceiling(t_cub3d *game);
void				ft_draw(t_cub3d *game);
void				ft_draw_sprite(t_cub3d *game, int i);
void				ft_calculate_sprite(t_cub3d *game, int x);
void				ft_save_bitmap(char *filename, t_cub3d *game);
void				ft_init_game_struct(t_cub3d *game);
void				ft_fov_init(t_cub3d *game);
void				ft_texture_init(t_cub3d *game);
void				ft_exit_texture(t_cub3d *game);
void				ft_check_map_arg(t_cub3d *game, char *line, int i);
void				ft_colors(t_cub3d *game, char *line, int i, int j);
void				ft_texture_path(t_cub3d *game, char *line, int i);
void				ft_alloc_sprite_order(t_cub3d *game);
void				ft_check_in_map_space(t_cub3d *game, int i, int j);
void				ft_count_map_args(t_cub3d *game, char *line, int i);
char				*ft_strdup_texture(char *s1);
int					ft_is_map_ok(t_cub3d *game, int i, int n, int o);
void				ft_is_enough_arg(t_cub3d *game);
void				ft_catch_res(t_cub3d *game, char *line, int i);
int					ft_check_is_empty_line(char *line);
void				ft_is_out_of_map(t_cub3d *game, int i, int j);
void				ft_check_map_closed_left(t_cub3d *game, int i, int j,
					char c);
void				ft_check_map_closed_right(t_cub3d *game, int i, int j,
					char c);
void				ft_check_0_out(t_cub3d *game, int i, int j);
void				ft_del_last_line(t_cub3d *game, int i);
void				ft_first_and_last_check(t_cub3d *game, int i);
void				ft_check_empty_line(t_cub3d *game, int i, int j, int s);
void				ft_win(t_cub3d *game, int h, int w, int *vic_data);

#endif
