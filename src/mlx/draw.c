/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:01:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/20 14:39:21 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_vertical_line(t_cub3d *cube, t_raycast *ray, int x, t_draw *draw)
{
	t_img	*texture;
	int		tex_x;
	int		tex_y;
	int		y;
	int		color;
	double	step;
	double	tex_pos;
	double	wallX;
	char	*texture_pixel;
	char	*buffer_pixel;

	// Calcul de la coordonnée x de la texture (wallX)
	// wallX représente le point exact où le rayon a touché le mur
	if (!cube->buffer.addr)
	{
		printf("Error: Buffer address is NULL\n");
		return ;
	}
	if (ray->side == 0)
		wallX = cube->player.pos_y + ray->wall_dist * ray->ray_dir_y;
	else
		wallX = cube->player.pos_x + ray->wall_dist * ray->ray_dir_x;
	wallX -= floor(wallX); //floor permet une normalisation entre 0 et 1
	// Sélection de la texture selon le côté touché
	if (ray->side == 0 && ray->ray_dir_x > 0)
		texture = &cube->textures.east;
	else if (ray->side == 0)
		texture = &cube->textures.west;
	else if (ray->ray_dir_y > 0)
		texture = &cube->textures.south;
	else
		texture = &cube->textures.north;
	// Calcul de la coordonnée x de la texture
	tex_x = (int)(wallX * texture->width);
	// Inversion de la texture si nécessaire pour éviter l'effet miroir
	if ((ray->side == 0 && ray->ray_dir_x < 0) ||
		(ray->side == 1 && ray->ray_dir_y > 0))
		tex_x = texture->width - tex_x - 1;
	// Calcul du pas de texture et de la position de départ
	step = 1.0 * texture->height / draw->line_height;
	tex_pos = (draw->start - cube->screen_height / 2 +
				draw->line_height / 2) *
		step;
	// Boucle de dessin de la ligne verticale
	y = draw->start;
	while (y < draw->end)
	{
		// Calcul de la coordonnée y de la texture
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		// Récupération de la couleur dans la texture
		texture_pixel = texture->addr + (tex_y * texture->size_line + tex_x
				* (texture->bits_per_pixel / 8));
		color = *(unsigned int *)texture_pixel;
		// Assombrissement si c'est un côté y (optionnel, pour l'effet 3D)
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		// Calcul de la position dans le buffer
		buffer_pixel = cube->buffer.addr + (y * cube->buffer.size_line + x
				* (cube->buffer.bits_per_pixel / 8));
		*(unsigned int *)buffer_pixel = color;
		y++;
	}
}
void	calculate_draw_points(t_cub3d *cube, t_raycast *ray, t_draw *draw)
{
	// Calcul de la hauteur de la ligne à dessiner
	draw->line_height = (int)(cube->screen_height / ray->wall_dist);
	// Calcul des points de début et de fin
	draw->start = -draw->line_height / 2 + cube->screen_height / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = draw->line_height / 2 + cube->screen_height / 2;
	if (draw->end >= cube->screen_height)
		draw->end = cube->screen_height - 1;
}

int	draw_background(t_cub3d *cube)
{
	int	*buffer;
	int ceiling_color;
	int floor_color;
	int half_screen;
	int i;

	// definition de la couleur == (red << 16)|(green << 8)|(blue)
	// les 8 bits les plus significatif correspondent au alpha == transparence
	ceiling_color = (135 << 16) | (206 << 8) | 250;
	floor_color = (255 << 16) | (248 << 8) | 220;
	buffer = (int *)cube->buffer.addr;
	if (!buffer)
		return(printf("Error: empty buffer\n"),1);
	half_screen = (cube->screen_width * cube->screen_height) / 2;
	i = 0;
	while (i < half_screen)
	{
		buffer[i] = ceiling_color;
		i ++;
	}
	while (i < cube->screen_width * cube->screen_height)
	{
		buffer[i] = floor_color;
		i ++;
	}
	return (0);
}
