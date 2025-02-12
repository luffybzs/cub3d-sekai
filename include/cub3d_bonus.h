/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:47 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/12 14:11:56 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cube3d_bonus_h
# define cube3d_bonus_h

# include "../minilibx-linux/mlx.h"
# include "./../libft/get_next_line/get_next_line.h"
# include "./../libft/libft.h"
# include "gc.h"
# include <X11/keysym.h> //keycode
# include <math.h>       // math fonction
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_LEFT XK_Left
# define KEY_RIGHT XK_Right
# define KEY_RETURN XK_Return

# define MINIMAP_SCALE 0.2 // echelle de la minimap (en %)
# define BLOCK_SIZE 7      // taille du player

# define ERROR_FOR_INFO "Error\nThere is missing information or there are duplicates"

typedef struct s_img
{
	void	*img;
	char	*path;
	char	*addr;
	int		size_line;
	int		bits_per_pixel;
	int		line_length;
	int		endiant;
	int		width;
	int		height;
}			t_img;

typedef struct s_draw
{ // gestion des lignes de dessins point de depart fin et taille
	int		start;
	int		end;
	int		line_height;
}			t_draw;

typedef struct s_textures
{
	t_img north; // Texture du mur nord
	t_img south; // Texture du mur sud
	t_img west;  // Texture du mur ouest
	t_img east;  // Texture du mur est
}			t_textures;

typedef struct s_player
{
	char direction; // N,S,E,W
	double pos_x;   // Position X du joueur
	double pos_y;   // Position Y du joueur
	double dir_x;   // Direction X du joueur
	double dir_y;   // Direction Y du joueur
	double plane_x; // Plan de la caméra X
	double plane_y; // Plan de la caméra Y
}			t_player;

typedef struct s_raycast
{
	// position de depart du rayon == position du player
	double	pos_x;
	double	pos_y;

	// direction du rayon == plan camera et direction du joueur
	double	ray_dir_x;
	double	ray_dir_y;

	// case de la grille origine du rayon
	int		map_x;
	int		map_y;

	// distance aux prochaines intersections (jusqu a la prochaine case de map)
	double	side_dist_x;
	double	side_dist_y;

	// distance entre deux lignes vertciale/horizontale
	double	delta_dist_x;
	double	delta_dist_y;

	// direction de progression des rayons si il doit aller vers la gauche ou la droite
	int		step_x;
	int		step_y;

	// distance finale == point d impact
	//- joueur(distance perpendiculaire au mur eviter le flou)
	double	wall_dist;

	// indicateur de face quel mur est touchee
	int		side;
	int		ray_hit_door;

}			t_raycast;

typedef struct s_cub3d
{
	void *mlx;         // Pointeur MLX
	void *win;         // Pointeur fenêtre
	int screen_width;  // Largeur de l'écran
	int screen_height; // Hauteur de l'écran
	// char **map;          //juste map pour le moment
	t_img buffer;        // gestion de la toile
	t_textures textures; // Toutes les textures autre que le buffer
	t_player player;     // Informations du joueur
	double	*z_buffer;
	// tableau qui stock la distance entre la camera et les points
	int		map_width;
	int		map_height;

	// partie parsing
	char	**all_maps;
	char	**map;
	char	*av1;
	int		ac;
	// point cardinaux
	char	*EA;
	char	*WE;
	char	*SO;
	char	*NO;
	// parsing de couleurs
	char	*F;
	char	*C;
	// couleur floor
	int		F_R;
	int		F_G;
	int		F_B;
	// couleur ceiling
	int		C_R;
	int		C_G;
	int		C_B;
	// player info
	char	direction;
	int		y_spwan_p;
	int		x_spwan_p;
	// implementation de la minimap
	t_img	minimap;
	int		height;
	int		width;
	// door
	t_img	door;
	// control on mouse mouvement
	int		enable_mouse;
}			t_cub3d;

int			ft_atoi_rgb(char *str, int start, int end);
int			ft_search_maps(char *av1, t_cub3d *cube3d);
int			ft_all_one(char *str);
int			ft_cmp_xpm(char *str, int i, char *cmp);
int			ft_add_C(char *str, t_cub3d *cube3d);
int			ft_add_F(char *str, t_cub3d *cube3d);
char		*ft_add_just_info(char *str, int i);
int			ft_add_NO(char *str, t_cub3d *cube3d, int i);
int			ft_add_EA(char *str, t_cub3d *cube3d, int i);
int			ft_add_SO(char *str, t_cub3d *cube3d, int i);
int			ft_add_WE(char *str, t_cub3d *cube3d, int i);
int			ft_add_cardinal_points(char *str, t_cub3d *cube3d, int i);
int			ft_check_av1(t_cub3d *cube3d);
void		ft_fail_free(t_cub3d *cube3d);
int			ft_fill_data(int ac, char **av, t_cub3d *cube3d);
int			ft_search_info(char *av1, t_cub3d *cube3d);

/* screen handler */
int			init_mlx(t_cub3d *data);
int			close_window(t_cub3d *data);
void		cleanup(t_cub3d *data);
void		cleanup2(t_cub3d *data);

/* draw */
int			init_textures(t_cub3d *cube);
int			load_texture(void *mlx, t_img *img, char *path);
int			render(t_cub3d *cube);
int			init_textures(t_cub3d *cube);
int			open_images(t_cub3d *cube);
int			init_buffer(t_cub3d *cube);
int			ft_init_img(t_cub3d *cube, t_img *img);
int			init_textures_path(t_cub3d *cube);
void		draw_vertical_line(t_cub3d *cube, t_raycast *ray, int x,
				t_draw *draw);
void		calculate_draw_points(t_cub3d *cube, t_raycast *ray, t_draw *draw);
int			draw_background(t_cub3d *cube);
void		calculate_wall_x(t_cub3d *cube, t_raycast *ray, double *wall_x);
void		select_wall_texture(t_cub3d *cube, t_raycast *ray, t_img **texture);
int			get_texture_x(t_raycast *ray, double wall_x, t_img *texture);
void		init_texture_values(t_cub3d *cube, t_draw *draw, t_img *texture,
				double *tex_pos, double *step);
int			get_pixel_color(t_img *texture, int tex_x, int tex_y, int side);
void		put_pixel_to_buffer(t_cub3d *cube, int x, int y, int color);

/* raycasting */
void		perform_dda(t_cub3d *cube, t_raycast *ray);

/* event in game */

int			key_press(int keycode, t_cub3d *map);
void		key_press2(t_cub3d *cube, int keycode);
void		init_player(t_cub3d *cube);
void		init_player2(t_cub3d *cube);
void		move_backward(t_cub3d *cube);
void		rotate_left(t_cub3d *cube);
void		rotate_right(t_cub3d *cube);
void		move_forward(t_cub3d *cube);
void		move_right(t_cub3d *cube);
void		move_left(t_cub3d *cube);

/* init data */
int			init_cub3d(t_cub3d *cube);
void		calculate_step_and_side_dist(t_raycast *ray);
void		init_ray(t_cub3d *cube, t_raycast *ray, double camera_x);
void		raycasting(t_cub3d *cube);

// parsing

int			ft_atoi_rgb(char *str, int start, int end);
int			ft_search_maps(char *av1, t_cub3d *cube3d);
int			ft_all_one(char *str);
int			ft_cmp_xpm(char *str, int i, char *cmp);
int			ft_add_C(char *str, t_cub3d *cube3d);
int			ft_add_F(char *str, t_cub3d *cube3d);
char		*ft_add_just_info(char *str, int i);
int			ft_add_NO(char *str, t_cub3d *cube3d, int i);
int			ft_add_EA(char *str, t_cub3d *cube3d, int i);
int			ft_add_SO(char *str, t_cub3d *cube3d, int i);
int			ft_add_WE(char *str, t_cub3d *cube3d, int i);
int			ft_add_cardinal_points(char *str, t_cub3d *cube3d, int i);
int			ft_check_av1(t_cub3d *cube3d);
void		ft_fail_free(t_cub3d *cube3d);
int			ft_fill_data(int ac, char **av, t_cub3d *cube3d);
int			ft_search_info(char *av1, t_cub3d *cube3d);
int			ft_fill_color(t_cub3d *cube3d);

/* bonus */
int			init_mini_map(t_cub3d *cube);
void		draw_minimap(t_cub3d *cube);
void		handle_door(t_cub3d *cube);
int			mouse_move(int x, int y, t_cub3d *cube);
void		rotate_angle(t_cub3d *cube, double angle);
void		rotate_left_mouse(t_cub3d *cube);
void		rotate_right_mouse(t_cub3d *cube);

/* temporaire */
char		**create_test_map(void);
void		test_print(char **map);

/* utils*/
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);

/*
- gerer les leaks
- finir de gerer les keyhook (principalement les mouvements de souris dans le cadre des bonus)
-
*/

#endif