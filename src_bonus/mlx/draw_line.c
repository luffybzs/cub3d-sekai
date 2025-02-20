/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:25:10 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/20 16:11:19 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	calculate_wall_x(t_cub3d *cube, t_raycast *ray, double *wall_x)
{
	if (ray->side == 0)
		*wall_x = cube->player.pos_y + ray->wall_dist * ray->ray_dir_y;
	else
		*wall_x = cube->player.pos_x + ray->wall_dist * ray->ray_dir_x;
	*wall_x -= floor(*wall_x);
}
void	select_wall_texture(t_cub3d *cube, t_raycast *ray, t_img **texture)
{
	if (cube->all_maps[ray->map_y][ray->map_x] == 'D')
	{
		*texture = &cube->door;
		return ;
	}
	if (ray->side == 0 && ray->ray_dir_x > 0)
		*texture = &cube->textures.east;
	else if (ray->side == 0)
		*texture = &cube->textures.west;
	else if (ray->ray_dir_y > 0)
		*texture = &cube->textures.south;
	else
		*texture = &cube->textures.north;
}

int	get_texture_x(t_raycast *ray, double wall_x, t_img *texture)
{
	int	tex_x;

	tex_x = (int)(wall_x * texture->width);
	if ((ray->side == 0 && ray->ray_dir_x < 0) || (ray->side == 1
			&& ray->ray_dir_y > 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

void	init_texture_values(t_draw *draw, t_img *texture, double *step)
{
	*step = 1.0 * texture->height / draw->line_height;
}

int	get_pixel_color(t_img *texture, int tex_x, int tex_y, int side)
{
	char			*texture_pixel;
	unsigned int	color;

	texture_pixel = texture->addr + (tex_y * texture->size_line + tex_x
			* (texture->bits_per_pixel / 8));
	color = *(unsigned int *)texture_pixel;
	if (side == 1)
		color = (color >> 1) & 8355711;
	return (color);
}
