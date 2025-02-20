/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:36:54 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/20 16:09:24 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	raycasting(t_cub3d *cube)
{
	t_raycast	ray;
	t_draw		draw;
	double		camera_x;
	int			x;

	if (!cube || !cube->buffer.addr || !cube->all_maps)
	{
		printf("Error:\nInvalid cube structure\n");
		return ;
	}
	x = 0;
	while (x < cube->screen_width)
	{
		camera_x = 2 * x / (double)cube->screen_width - 1;
		init_ray(cube, &ray, camera_x);
		calculate_step_and_side_dist(&ray);
		perform_dda(cube, &ray);
		cube->z_buffer[x] = ray.wall_dist;
		calculate_draw_points(cube, &ray, &draw);
		draw_vertical_line(cube, &ray, x, &draw);
		x++;
	}
}

void	init_ray(t_cub3d *cube, t_raycast *ray, double camera_x)
{
	ray->pos_x = cube->player.pos_x;
	ray->pos_y = cube->player.pos_y;
	ray->ray_dir_x = cube->player.dir_x + cube->player.plane_x * camera_x;
	ray->ray_dir_y = cube->player.dir_y + cube->player.plane_y * camera_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	calculate_step_and_side_dist(t_raycast *ray)
{
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
	if (!perform_sub_dda(cube, ray))
		return ;
	while (!hit)
	{
		handle_intersection(ray);
		if (ray->map_y < 0 || ray->map_y >= cube->map_height || ray->map_x < 0
			|| ray->map_x >= cube->map_width)
			break ;
		if (cube->all_maps[ray->map_y][ray->map_x] == '1'
			|| cube->all_maps[ray->map_y][ray->map_x] == 'D')
		{
			hit = 1;
			if (cube->all_maps[ray->map_y][ray->map_x] == 'D')
				ray->ray_hit_door = 1;
		}
	}
	if (ray->side == 0)
		ray->wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

int	perform_sub_dda(t_cub3d *cube, t_raycast *ray)
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
