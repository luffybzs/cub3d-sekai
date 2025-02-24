/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:01:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/24 12:19:53 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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

	ceiling_color = (cube->c_r << 16) | (cube->c_g << 8) | cube->c_b;
	floor_color = (cube->f_r << 16) | (cube->f_g << 8) | cube->f_b;
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

void	put_pixel_to_buffer(t_cub3d *cube, int x, int y, int color)
{
	char	*buffer_pixel;

	buffer_pixel = cube->buffer.addr + (y * cube->buffer.size_line + x
			* (cube->buffer.bits_per_pixel / 8));
	*(unsigned int *)buffer_pixel = color;
}

void	draw_vertical_line(t_cub3d *cube, t_raycast *ray, int x, t_draw *draw)
{
	t_trash	full;
	int		y;

	if (!cube->buffer.addr || !cube || !ray || !draw)
		return ;
	calculate_wall_x(cube, ray, &full.wall_x);
	select_wall_texture(cube, ray, &full.texture);
	full.tex_coords[0] = get_texture_x(ray, full.wall_x, full.texture);
	init_texture_values(draw, full.texture, &full.step);
	full.tex_pos = init_texture_values2(draw, cube, &full.step);
	y = draw->start;
	while (y < draw->end)
	{
		full.tex_coords[1] = (int)full.tex_pos & (full.texture->height - 1);
		full.tex_pos += full.step;
		full.color = get_pixel_color(full.texture, full.tex_coords[0],
				full.tex_coords[1], ray->side);
		put_pixel_to_buffer(cube, x, y, full.color);
		y++;
	}
}

double	init_texture_values2(t_draw *draw, t_cub3d *cube, double *step)
{
	return ((draw->start - cube->screen_height / 2 + draw->line_height / 2)
		* *step);
}
