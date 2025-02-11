/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:36:54 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/11 16:13:32 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	raycasting(t_cub3d *cube)
{
	t_raycast	ray;
	t_draw		draw;
	double		camera_x;
	int			x;

	if (!cube || !cube->buffer.addr || !cube->all_maps)
	{
		printf("Error: Invalid cube structure\n");
		return ;
	}
	x = 0;
	while (x < cube->screen_width)
	{
		// Calcul de la position du rayon sur le plan caméra
		camera_x = 2 * x / (double)cube->screen_width - 1;
		// Initialisation du rayon
		init_ray(cube, &ray, camera_x);
		// Calcul des pas et distances initiales
		calculate_step_and_side_dist(&ray);
		// calcule pour trouver l intersection avec le mur
		perform_dda(cube, &ray); //digital differential analysis
		cube->z_buffer[x] = ray.wall_dist;
		// Calcul des points de dessin et dessin
		calculate_draw_points(cube, &ray, &draw);
		draw_vertical_line(cube, &ray, x, &draw);
		x++;
	}
}

void	init_ray(t_cub3d *cube, t_raycast *ray, double camera_x)
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
	// prends toujours la valeurs absolue
}
void	calculate_step_and_side_dist(t_raycast *ray)
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

void	perform_dda(t_cub3d *cube, t_raycast *ray)
{
	int	hit;

	hit = 0;
	if (!check_boundaries(cube, ray))
		return;
	while (!hit)
	{
		// On avance à la prochaine intersection
		if (ray->side_dist_x < ray->side_dist_y)
			intersection(cube,ray);
		else
			intersection2(cube,ray);
		// Vérification des limites de la map
		if (ray->map_y < 0 || ray->map_y >= cube->map_height ||
			ray->map_x < 0 || ray->map_x >= cube->map_width)
			break ;
		// Vérification si on a touché un mur
		if (cube->all_maps[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
	calculate_distance(ray);
}

int	check_boundaries(t_cub3d *cube, t_raycast *ray)
{
	(void)ray;
	if (!cube->all_maps)
	{
		printf("Error: Map is NULL\n");
		return (0);
	}
	if (cube->map_width == 0 || cube->map_height == 0)
	{
		printf("Error: Invalid map dimensions\n");
		return (0);
	}
	return (1);
}
