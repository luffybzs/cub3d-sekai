/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:47 by ayarab            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/11 04:45:56 by ayarab           ###   ########.fr       */
=======
/*   Updated: 2025/01/10 17:34:15 by wdaoudi-         ###   ########.fr       */
>>>>>>> raytracing
/*                                                                            */
/* ************************************************************************** */

#ifndef cube3d_h
# define cube3d_h

#include "gc.h"
#include "./../libft/libft.h"
#include "./../libft/get_next_line/get_next_line.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_cub3d
{
    char **all_maps;
	char **map;
    char *av1;
    char *EA;
    char *WE;
    char *SO;
    char *NO;
	char *F;
	char *C;
    int    ac;
}    t_cub3d;

int ft_check_av1(t_cub3d *cube3d);
void ft_fail_free(t_cub3d *cube3d);
int ft_fill_data(int ac, char **av, t_cub3d *cube3d);
int ft_search_cardinal_points(t_cub3d *cube3d);
int ft_search_info(char *av1, t_cub3d *cube3d);

typedef struct s_player {
    double posX;            // Position X du joueur
    double posY;            // Position Y du joueur
    double dirX;           // Vecteur de direction X
    double dirY;           // Vecteur de direction Y
    double planeX;         // Plan caméra X (pour le FOV)
    double planeY;         // Plan caméra Y (pour le FOV)
    double moveSpeed;      // Vitesse de déplacement
    double rotSpeed;       // Vitesse de rotation
} t_player;

typedef struct s_ray {
    double cameraX;        // Position X sur le plan caméra
    double rayDirX;        // Direction X du rayon
    double rayDirY;        // Direction Y du rayon
    double sideDistX;      // Distance au prochain côté X
    double sideDistY;      // Distance au prochain côté Y
    double deltaDistX;     // Distance entre intersections X
    double deltaDistY;     // Distance entre intersections Y
    double perpWallDist;   // Distance perpendiculaire au mur
    int mapX;             // Position actuelle dans la map (X)
    int mapY;             // Position actuelle dans la map (Y)
    int stepX;            // Direction du pas en X (-1 ou 1)
    int stepY;            // Direction du pas en Y (-1 ou 1)
    int side;             // Quel côté du mur est touché (NS ou EW)
} t_ray;


#endif