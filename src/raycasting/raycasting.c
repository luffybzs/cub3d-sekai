/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:36:54 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/19 17:12:34 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void raycasting(t_cub3d *cube)
{
    t_raycast ray;
    double camera_x;
    int line_height;
    int draw_start;
    int draw_end;
    
    int x;
    
    x = 0;
    while (x < cube->screen_width)
    {
        // Calcul de la position sur le plan caméra
        camera_x = 2 * x / (double)cube->screen_width - 1;
        
        // Initialisation du rayon
        init_ray(cube, &ray, camera_x);
        
        // Calcul des pas et distances initiales
        calculate_step_and_side_dist(&ray);
        
        // Exécution du DDA
        perform_dda(cube, &ray);
        
        // Calcul de la hauteur de la ligne à dessiner
        line_height = (int)(cube->screen_height / ray.wall_dist);
        
        // Calcul du début et de la fin de la ligne
         draw_start = -line_height / 2 + cube->screen_height / 2;
         draw_end = line_height / 2 + cube->screen_height / 2;
        
        if (draw_start < 0)
            draw_start = 0;
        if (draw_end >= cube->screen_height)
            draw_end = cube->screen_height - 1;
        
        // Dessin de la ligne verticale
        draw_vertical_line(cube, x, draw_start, draw_end, ray.side);
        
        x++;
    }
}

void init_ray(t_cub3d *cube, t_raycast *ray, double camera_x)
{
    // Position initiale = position du joueur
    ray->pos_x = cube->player.pos_x;
    ray->pos_y = cube->player.pos_y;
    
    // Calcul de la direction du rayon
    ray->ray_dir_x = cube->player.dir_x + cube->player.plane_x * camera_x;
    ray->ray_dir_y = cube->player.dir_y + cube->player.plane_y * camera_x;
    
    // Position dans la map
    ray->map_x = (int)ray->pos_x;
    ray->map_y = (int)ray->pos_y;
    
    // Calcul des delta_dist
    // Ces valeurs représentent la distance entre deux intersections x ou y
    ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
    ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}
void calculate_step_and_side_dist(t_raycast *ray)
{
    // Calcul du sens et de la distance initiale en X
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
    }
    
    // Meme chose pour Y
    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
    }
}

void perform_dda(t_cub3d *cube, t_raycast *ray)
{
    int hit = 0; // Est-ce qu'on a touché un mur?

    while (!hit)
    {
        // On avance à la prochaine intersection x ou y (la plus proche)
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0; // On a touché un mur vertical
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1; // On a touché un mur horizontal
        }
        
        // Vérification si on a touché un mur
        if (cube->map[ray->map_x][ray->map_y] == '1')
            hit = 1;
    }
    
    // Calcul de la distance perpendiculaire(évite l'effet fish-eye)
    if (ray->side == 0)
        ray->wall_dist = (ray->map_x - ray->pos_x + 
            (1 - ray->step_x) / 2) / ray->ray_dir_x;
    else
        ray->wall_dist = (ray->map_y - ray->pos_y + 
            (1 - ray->step_y) / 2) / ray->ray_dir_y;
}
