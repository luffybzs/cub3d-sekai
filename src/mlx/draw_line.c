/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:25:10 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/20 15:27:14 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	calculate_wall_x(t_cub3d *cube, t_raycast *ray, double *wall_x)
{
	// point exact ou le rayon touche le mur
	if (ray->side == 0) // si side == 0 alors on a touche le mur vertical
		*wall_x = cube->player.pos_y + ray->wall_dist * ray->ray_dir_y;
	else // sinon mur horizontal
		*wall_x = cube->player.pos_x + ray->wall_dist * ray->ray_dir_x;
	*wall_x -= floor(*wall_x); // plus grand entier inferieur ou egale
}
void	select_wall_texture(t_cub3d *cube, t_raycast *ray, t_img **texture)
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
int	get_texture_x(t_raycast *ray, double wall_x, t_img *texture)
{
	int	tex_x;

	// permet de savoir quelle texture apposee et entraine l inversion des textures
	// afin d avoir les bonnes textures des deux cotees
	tex_x = (int)(wall_x * texture->width);
	if ((ray->side == 0 && ray->ray_dir_x < 0) || (ray->side == 1
			&& ray->ray_dir_y > 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

void	init_texture_values(t_draw *draw, t_img *texture, double *step)
{
	// calcule la taille du pixel a dessiner en fonction de la taille de
	// la ligne/taille de l ecran et la taille de l image
	// ainsi que le point de depart de la texture dans l image
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
		color = (color >> 1) & 8355711; // assombrissement des mur horizontal
	return (color);
}
