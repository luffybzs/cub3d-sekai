/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:01:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/12 18:01:15 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

int	get_pixel(t_img *img, int x, int y)
{
	char	*src;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		src = img->addr + (y * img->line_length + x * (img->bits_per_pixel
					/ 8));
		return (*(unsigned int *)src);
	}
	return (0);
}

// Pour créer une couleur RGB
int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	render(t_cub3d *cube)
{
	t_img buffer;

	buffer.img = mlx_new_image(cube->mlx, cube->screen_width,
			cube->screen_height);
	if (!buffer.img)
		return (1);
	buffer.addr = mlx_get_data_addr(buffer.img, &buffer.bits_per_pixel,
			&buffer.line_length, &buffer.endian);
	buffer.width = cube->screen_width;
	buffer.height = cube->screen_height;

	int middle_x = cube->screen_width / 2;
	int start_y = cube->screen_height / 4;
	int end_y = cube->screen_height * 3 / 4;

	while (start_y < end_y)
	{
		put_pixel(&buffer, middle_x, start_y, 0xFF0000);
		start_y++;
	}

	mlx_put_image_to_window(cube->mlx, cube->win, buffer.img, 0, 0);
	mlx_destroy_image(cube->mlx, buffer.img);
	return (0);
}