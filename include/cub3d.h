/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:47 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/19 16:59:39 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cube3d_h
# define cube3d_h

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

# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_LEFT XK_Left
# define KEY_RIGHT XK_Right

// typedef struct s_cub3d
// {
// 	char		**all_maps;
// 	char		**map;
// 	char		*av1;
// 	char		*EA;
// 	char		*WE;
// 	char		*SO;
// 	char		*NO;
// 	char		*S;
// 	char		*F;
// 	char		*C;
// 	int			ac;
// }				t_cub3d;

// typedef struct s_mlx_data
// {
// 	void		*mlx;
// 	void		*win;
// }				t_mlx_data;

// typedef struct s_map_info
// {
// 	// information sur la map
// 	int screen_width;  // largeur
// 	int screen_height; // hauteur

// 	t_cub3d		infos;
// 	t_mlx_data	mlx;
// }				t_map_info;

// tentatives
typedef struct s_colors
{
	int floor[3];   // RGB pour le sol
	int ceiling[3]; // RGB pour le plafond
}			t_colors;

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

typedef struct s_textures
{
	t_img north;  // Texture du mur nord
	t_img south;  // Texture du mur sud
	t_img west;   // Texture du mur ouest
	t_img east;   // Texture du mur est
	t_img sprite; // Texture des sprites ???
}			t_textures;

typedef struct s_player
{
	double pos_x;   // Position X du joueur
	double pos_y;   // Position Y du joueur
	double dir_x;   // Direction X du joueur
	double dir_y;   // Direction Y du joueur
	double plane_x; // Plan de la caméra X
	double plane_y; // Plan de la caméra Y
}			t_player;

typedef struct s_raycast
{
	//position de depart du rayon == position du player
	double	pos_x;
	double	pos_y;

	//direction du rayon == plan camera et direction du joueur
	double	ray_dir_x;
	double	ray_dir_y;

	// case de la grille origine du rayon
	int		map_x;
	int		map_y;

	//distance aux prochaines intersections (jusqu a la prochaine case de map)
	double	side_dist_x;
	double	side_dist_y;

	//distance entre deux lignes vertciale/horizontale
	double delta_dist_x;
	double delta_dist_y;

	//direction de progression des rayons si il doit aller vers la gauche ou la droite
	int step_x;
	int step_y;

	//distance finale == point d impact - joueur(distance perpendiculaire au mur eviter le flou)
	double wall_dist;

	//indicateur de face quel mur est touchee
	int side;

}			t_raycast;

typedef struct s_cub3d
{
	void *mlx;           // Pointeur MLX
	void *win;           // Pointeur fenêtre
	int screen_width;    // Largeur de l'écran
	int screen_height;   // Hauteur de l'écran
	t_textures textures; // Toutes les textures
	t_colors colors;     // Couleurs du sol/plafond
	char **map;           //juste map pour le moment
	t_img buffer;    // gestion des images
	t_player player; // Informations du joueur
}			t_cub3d;

int			ft_check_av1(t_cub3d *cube3d);
void		ft_fail_free(t_cub3d *cube3d);
int			ft_fill_data(int ac, char **av, t_cub3d *cube3d);
int			ft_search_cardinal_points(t_cub3d *cube3d);
int			ft_search_info(char *av1, t_cub3d *cube3d);

/* screen handler */
int			init_mlx(t_cub3d *data);
int			close_window(t_cub3d *data);
void		cleanup(t_cub3d *data);

/* draw */
int			init_textures(t_cub3d *cube);
int			load_texture(void *mlx, t_img *img, char *path);
void		put_pixel(t_img *img, int x, int y, int color);
int			get_pixel(t_img *img, int x, int y);
int			create_rgb(int r, int g, int b);
int			render(t_cub3d *cube);
int			init_textures(t_cub3d *cube);
int			open_images(t_cub3d *cube);
int			init_buffer(t_cub3d *cube);
int			ft_init_img(t_cub3d *cube, t_img *img);
int			init_textures_path(t_cub3d *cube);

/* raycasting */
void perform_dda(t_cub3d *cube, t_raycast *ray);

/* event in game */

int			key_press(int keycode, t_cub3d *map);
void		init_player(t_cub3d *cube);

/* init data */
int			init_cub3d(t_cub3d *cube);
void calculate_step_and_side_dist(t_raycast *ray);
void init_ray(t_cub3d *cube, t_raycast *ray, double camera_x);
void raycasting(t_cub3d *cube);

/* temporaire */
char **create_test_map(void);

/*
-gerer les mouvements les calculs et les gestions de collisions
- gerer les leaks
- finir de gerer les keyhook
*/


#endif