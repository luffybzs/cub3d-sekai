/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:25:10 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/04 15:00:57 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

static void	calculate_wall_x(t_cub3d *cube, t_raycast *ray, double *wall_x)
{
	// point exact ou le rayon touche le mur
	if (ray->side == 0) // si side == 0 alors on a touche le mur vertical
		*wall_x = cube->player.pos_y + ray->wall_dist * ray->ray_dir_y;
	else // sinon mur horizontal
		*wall_x = cube->player.pos_x + ray->wall_dist * ray->ray_dir_x;
	*wall_x -= floor(*wall_x); // plus grand entier inferieur ou egale
}
static void	select_wall_texture(t_cub3d *cube, t_raycast *ray, t_img **texture)
{
	// selection du mur a dessiner en fonction du side et de l orientation
	// et la direction du rayon
	if (ray->side == 0 && ray->ray_dir_x > 0)
		*texture = &cube->textures.east;
	else if (ray->side == 0)
		*texture = &cube->textures.west;
	else if (ray->ray_dir_y > 0)
		*texture = &cube->textures.south;
	else
		*texture = &cube->textures.north;
}
static int	get_texture_x(t_raycast *ray, double wall_x, t_img *texture)
{
	int	tex_x;

	//permet de savoir quelle texture apposee et entraine l inversion des textures
	// afin d avoir les bonnes textures des deux cotees
	tex_x = (int)(wall_x * texture->width);
	if ((ray->side == 0 && ray->ray_dir_x < 0) || (ray->side == 1
			&& ray->ray_dir_y > 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

static void	init_texture_values(t_cub3d *cube, t_draw *draw, t_img *texture,
		double *tex_pos, double *step)
{
	// calcule la taille du pixel a dessiner en fonction de la taille de
	//la ligne/taille de l ecran et la taille de l image
	//ainsi que le point de depart de la texture dans l image
	*step = 1.0 * texture->height / draw->line_height;
	*tex_pos = (draw->start - cube->screen_height / 2 + draw->line_height / 2)
		* *step;
}

static int	get_pixel_color(t_img *texture, int tex_x, int tex_y, int side)
{
	char			*texture_pixel;
	unsigned int	color;

	texture_pixel = texture->addr + (tex_y * texture->size_line + tex_x
			* (texture->bits_per_pixel / 8));
	color = *(unsigned int *)texture_pixel;
	if (side == 1)
		color = (color >> 1) & 8355711; // assombrissement des mur horizontal
	return (color);
}

static void	put_pixel_to_buffer(t_cub3d *cube, int x, int y, int color)
{
	char	*buffer_pixel;

	buffer_pixel = cube->buffer.addr + (y * cube->buffer.size_line + x
			* (cube->buffer.bits_per_pixel / 8));
	*(unsigned int *)buffer_pixel = color;
}

void	draw_vertical_line(t_cub3d *cube, t_raycast *ray, int x, t_draw *draw)
{
	t_img			*texture;
	double			wall_x;
	double			step;
	double			tex_pos;
	int				tex_coords[2];
	int				y;
	unsigned int	color;

	if (!cube->buffer.addr || !cube || !ray || !draw)
		return ;
	calculate_wall_x(cube, ray, &wall_x);
	select_wall_texture(cube, ray, &texture);
	tex_coords[0] = get_texture_x(ray, wall_x, texture);
	init_texture_values(cube, draw, texture, &tex_pos, &step);
	y = draw->start;
	while (y < draw->end)
	{
		tex_coords[1] = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = get_pixel_color(texture, tex_coords[0], tex_coords[1],
				ray->side);
		put_pixel_to_buffer(cube, x, y, color);
		y++;
	}
}
