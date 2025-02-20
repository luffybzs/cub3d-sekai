/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:47 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/20 18:34:26 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "./../libft/get_next_line/get_next_line.h"
# include "./../libft/libft.h"
# include "gc.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define KEY_W XK_W
# define KEY_A XK_A
# define KEY_S XK_S
# define KEY_D XK_D
# define KEY_LEFT XK_LEFT
# define KEY_RIGHT XK_RIGHT

typedef struct s_img
{
	void			*img;
	char			*path;
	char			*addr;
	int				size_line;
	int				bits_per_pixel;
	int				line_length;
	int				endiant;
	int				width;
	int				height;
}					t_img;

typedef struct s_trash
{
	t_img			*texture;
	double			wall_x;
	double			step;
	double			tex_pos;
	int				tex_coords[2];
	unsigned int	color;

}					t_trash;

typedef struct s_draw
{
	int				start;
	int				end;
	int				line_height;
}					t_draw;

typedef struct s_textures
{
	t_img			north;
	t_img			south;
	t_img			west;
	t_img			east;
}					t_textures;

typedef struct s_player
{
	char			direction;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct s_raycast
{
	double			pos_x;
	double			pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	double			wall_dist;
	int				side;
}					t_raycast;

typedef struct s_cub3d
{
	void			*mlx;
	void			*win;
	int				screen_width;
	int				screen_height;
	t_img			buffer;
	t_textures		textures;
	t_player		player;
	double			*z_buffer;
	int				map_width;
	int				map_height;
	char			**all_maps;
	char			**map;
	char			*av1;
	int				ac;
	char			*EA;
	char			*WE;
	char			*SO;
	char			*NO;
	char			*F;
	char			*C;
	int				F_R;
	int				F_G;
	int				F_B;
	int				C_R;
	int				C_G;
	int				C_B;
	char			direction;
	int				y_spwan_p;
	int				x_spwan_p;
}					t_cub3d;

int					ft_atoi_rgb(char *str, int start, int end);
int					ft_search_maps(char *av1, t_cub3d *cube3d);
int					ft_all_one(char *str);
int					ft_cmp_xpm(char *str, int i, char *cmp);
int					ft_add_C(char *str, t_cub3d *cube3d);
int					ft_add_F(char *str, t_cub3d *cube3d);
char				*ft_add_just_info(char *str, int i);
int					ft_add_NO(char *str, t_cub3d *cube3d, int i);
int					ft_add_EA(char *str, t_cub3d *cube3d, int i);
int					ft_add_SO(char *str, t_cub3d *cube3d, int i);
int					ft_add_WE(char *str, t_cub3d *cube3d, int i);
int					ft_add_cardinal_points(char *str, t_cub3d *cube3d, int i);
int					ft_check_av1(t_cub3d *cube3d);
void				ft_fail_free(t_cub3d *cube3d);
int					ft_fill_data(int ac, char **av, t_cub3d *cube3d);
int					ft_search_info(char *av1, t_cub3d *cube3d);

/* screen handler */
int					init_mlx(t_cub3d *data);
int					close_window(t_cub3d *data);
void				cleanup(t_cub3d *data);

/* draw */
int					init_textures(t_cub3d *cube);
int					load_texture(void *mlx, t_img *img, char *path);
int					render(t_cub3d *cube);
int					init_textures(t_cub3d *cube);
int					open_images(t_cub3d *cube);
int					init_buffer(t_cub3d *cube);
int					ft_init_img(t_cub3d *cube, t_img *img);
int					init_textures_path(t_cub3d *cube);
void				draw_vertical_line(t_cub3d *cube, t_raycast *ray, int x,
						t_draw *draw);
void				calculate_draw_points(t_cub3d *cube, t_raycast *ray,
						t_draw *draw);
int					draw_background(t_cub3d *cube);
void				calculate_wall_x(t_cub3d *cube, t_raycast *ray,
						double *wall_x);
void				select_wall_texture(t_cub3d *cube, t_raycast *ray,
						t_img **texture);
int					get_texture_x(t_raycast *ray, double wall_x,
						t_img *texture);
void				init_texture_values(t_draw *draw, t_img *texture,
						double *step);
int					get_pixel_color(t_img *texture, int tex_x, int tex_y,
						int side);
void				init_textures_values2(t_draw *draw, t_cub3d *cube,
						double *tex_pos, double *step);

/* raycasting */
void				perform_dda(t_cub3d *cube, t_raycast *ray);
int					check_boundaries(t_cub3d *cube, t_raycast *ray);
void				calculate_distance(t_raycast *ray);
void				intersection(t_cub3d *cube, t_raycast *ray);
void				intersection2(t_cub3d *cube, t_raycast *ray);

/* event in game */

int					key_press(int keycode, t_cub3d *map);
void				init_player(t_cub3d *cube);
void				init_player2(t_cub3d *cube);
void				move_backward(t_cub3d *cube);
void				rotate_left(t_cub3d *cube);
void				rotate_right(t_cub3d *cube);
void				move_forward(t_cub3d *cube);
void				move_right(t_cub3d *cube);
void				move_left(t_cub3d *cube);

/* init data */
int					init_cub3d(t_cub3d *cube);
void				calculate_step_and_side_dist(t_raycast *ray);
void				init_ray(t_cub3d *cube, t_raycast *ray, double camera_x);
void				raycasting(t_cub3d *cube);

int					ft_atoi_rgb(char *str, int start, int end);
int					ft_search_maps(char *av1, t_cub3d *cube3d);
int					ft_all_one(char *str);
int					ft_cmp_xpm(char *str, int i, char *cmp);
int					ft_add_c(char *str, t_cub3d *cube3d);
int					ft_add_f(char *str, t_cub3d *cube3d);
char				*ft_add_just_info(char *str, int i);
int					ft_add_no(char *str, t_cub3d *cube3d, int i);
int					ft_add_ea(char *str, t_cub3d *cube3d, int i);
int					ft_add_so(char *str, t_cub3d *cube3d, int i);
int					ft_add_we(char *str, t_cub3d *cube3d, int i);
int					ft_add_cardinal_points(char *str, t_cub3d *cube3d, int i);
int					ft_check_av1(t_cub3d *cube3d);
void				ft_fail_free(t_cub3d *cube3d);
int					ft_fill_data(int ac, char **av, t_cub3d *cube3d);
int					ft_search_info(char *av1, t_cub3d *cube3d);
int					ft_fill_color(t_cub3d *cube3d);
int					ft_check_player(t_cub3d *cube3d);
int					ft_maps_is_good(t_cub3d *cube3d);
int					ft_check_line(char **tab);
int					ft_fill_info(t_cub3d *cube3d, char *str);
int					ft_ft(t_cub3d *cube3d, int i, int j);
int					ft_is_good(t_cub3d *cube3d, int j, int i);
int					ft_player(char c);
int					ft_is_all_good_char(t_cub3d *cube3d);
int					ft_skip(char **tab, int j);
void				ft_init_pos(t_cub3d *cube3d, int i, int j);
/* temporaire */
char				**create_test_map(void);
void				test_print(char **map);

#endif