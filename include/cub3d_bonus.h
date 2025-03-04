/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:47 by ayarab            #+#    #+#             */
/*   Updated: 2025/03/04 16:36:12 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "./../libft/get_next_line/get_next_line.h"
# include "./../libft/libft.h"
# include "gc.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define MINIMAP_SCALE 0.2
# define BLOCK_SIZE 5

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

typedef struct s_trash_2
{
	int				player_x;
	int				player_y;
	double			max_interact_distance;
	int				target_x;
	int				target_y;
	double			distance;

}					t_trash_2;

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
	int				ray_hit_door;

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
	char			*ea;
	char			*we;
	char			*so;
	char			*no;
	char			*f;
	char			*c;
	int				f_r;
	int				f_g;
	int				f_b;
	int				c_r;
	int				c_g;
	int				c_b;
	char			direction;
	int				y_spwan_p;
	int				x_spwan_p;
	t_img			minimap;
	int				height;
	int				width;
	t_img			door;
	int				enable_mouse;
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
int					ft_fill_space_in_wall(t_cub3d *cube3d);
int					ft_strdup_maps(t_cub3d *cube3d, int fd, char *line);
int					ft_line_space(char *line);
int					ft_add_key(t_cub3d *cube3d, int fd);
int					ft_check_key(char *line);
int					ft_fill_info(t_cub3d *cube3d, char *str);
char				*skip_space(char *line);

/* screen handler */
int					init_mlx(t_cub3d *data);
int					close_window(t_cub3d *data);
void				cleanup(t_cub3d *data);
void				cleanup2(t_cub3d *data);

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
double				init_texture_values2(t_draw *draw, t_cub3d *cube,
						double *step);
int					get_pixel_color(t_img *texture, int tex_x, int tex_y,
						int side);
void				put_pixel_to_buffer(t_cub3d *cube, int x, int y, int color);

/* raycasting */
void				perform_dda(t_cub3d *cube, t_raycast *ray);
int					perform_sub_dda(t_cub3d *cube, t_raycast *ray);
void				handle_intersection(t_raycast *ray);

/* event in game */

int					key_press(int keycode, t_cub3d *map);
void				key_press2(t_cub3d *cube, int keycode);
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
int					ft_add_door(char *str, t_cub3d *cube3d, int i);
int					ft_check_line(char **tab);
int					ft_ft(t_cub3d *cube3d, int i, int j);
int					ft_is_good(t_cub3d *cube3d, int j, int i);
int					ft_skip(char **tab, int j);
int					ft_maps_is_good(t_cub3d *cube3d);
void				ft_init_pos(t_cub3d *cube3d, int i, int j);
int					ft_player(char c);
int					find_width(t_cub3d *cube);

/* bonus */
int					init_mini_map(t_cub3d *cube);
void				draw_minimap(t_cub3d *cube);
void				handle_door(t_cub3d *cube);
int					mouse_move(int x, int y, t_cub3d *cube);
void				rotate_angle(t_cub3d *cube, double angle);
void				rotate_left_mouse(t_cub3d *cube);
void				rotate_right_mouse(t_cub3d *cube);

/* temporaire */
char				**create_test_map(void);
void				test_print(char **map);

/* utils*/
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif