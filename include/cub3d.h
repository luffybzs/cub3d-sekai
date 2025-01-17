/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:47 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/17 14:51:06 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cube3d_h
# define cube3d_h

# include "../minilibx-linux/mlx.h"
# include "./../libft/get_next_line/get_next_line.h"
# include "./../libft/libft.h"
# include "gc.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

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
// 	void		*no_img;
// 	void		*so_img;
// 	void		*we_img;
// 	void		*ea_img;
// 	void		*sprite_img;
// 	void		*floor_img;
// 	void		*ceiling_img;

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

typedef struct s_cub3d
{
	void *mlx;           // Pointeur MLX
	void *win;           // Pointeur fenêtre
	int screen_width;    // Largeur de l'écran
	int screen_height;   // Hauteur de l'écran
	t_textures textures; // Toutes les textures
	t_colors colors;     // Couleurs du sol/plafond
	// t_map map;           // Informations de la map
	t_img *img;          // gestion des images
	t_player player;     // Informations du joueur
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

/* event in game */

int			key_press(int keycode, t_cub3d *map);
void		init_player(t_cub3d *cube);

/* init data */
int			init_cub3d(t_cub3d *cube);

#endif