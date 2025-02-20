/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:01:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/20 15:25:55 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	calculate_draw_points(t_cub3d *cube, t_raycast *ray, t_draw *draw)
{
	draw->line_height = (int)(cube->screen_height / ray->wall_dist);
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
	int	ceiling_color;
	int	floor_color;
	int	half_screen;
	int	i;

	ceiling_color = (cube->C_R << 16) | (cube->C_G << 8) | cube->C_B;
	floor_color = (cube->F_R << 16) | (cube->F_G << 8) | cube->F_B;
	buffer = (int *)cube->buffer.addr;
	if (!buffer)
		return (printf("Error: empty buffer\n"), 1);
	half_screen = (cube->screen_width * cube->screen_height) / 2;
	i = 0;
	while (i < half_screen)
	{
		buffer[i] = ceiling_color;
		i++;
	}
	while (i < cube->screen_width * cube->screen_height)
	{
		buffer[i] = floor_color;
		i++;
	}
	return (0);
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
	init_texture_values(draw, texture, &step);
	init_textures_values2(draw,cube,&tex_pos,&step);
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
void	init_textures_values2(t_draw *draw, t_cub3d *cube, double *tex_pos,double *step)
{
	*tex_pos = (draw->start - cube->screen_height / 2 + draw->line_height / 2)
		* *step;
}