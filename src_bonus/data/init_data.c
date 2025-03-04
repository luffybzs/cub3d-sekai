/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:31:23 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/04 16:43:49 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	init_cub3d(t_cub3d *cube)
{
	if (!cube->all_maps)
		return (1);
	cube->map_height = 0;
	while (cube->all_maps[cube->map_height])
		cube->map_height++;
	if (find_width(cube) == 1)
		return (1);
	if (!init_textures_path(cube))
		return (printf("fail to init paths\n"), 1);
	init_player(cube);
	if (init_mlx(cube) || !cube->mlx || !cube->win)
		return (printf("fail to init MLX\n"), 1);
	cube->z_buffer = malloc(sizeof(double) * cube->screen_width);
	if (!cube->z_buffer)
		return (1);
	if (!open_images(cube))
		return (printf("fail to init textures\n"), 1);
	return (0);
}

int	open_images(t_cub3d *cube)
{
	if (!init_buffer(cube))
		return (0);
	if (!ft_init_img(cube, &cube->textures.north) || !ft_init_img(cube,
			&cube->textures.south) || !ft_init_img(cube, &cube->textures.west)
		|| !ft_init_img(cube, &cube->textures.east))
		return (0);
	if (cube->door.path)
		if (!ft_init_img(cube, &cube->door))
			return (0);
	return (1);
}

int	init_buffer(t_cub3d *cube)
{
	if (!cube->mlx)
		return (0);
	cube->buffer.img = mlx_new_image(cube->mlx, cube->screen_width,
			cube->screen_height);
	if (!cube->buffer.img)
		return (0);
	cube->buffer.addr = mlx_get_data_addr(cube->buffer.img,
			&cube->buffer.bits_per_pixel, &cube->buffer.size_line,
			&cube->buffer.endiant);
	if (!cube->buffer.addr)
		return (0);
	return (1);
}

int	ft_init_img(t_cub3d *cube, t_img *img)
{
	if (!img->path)
	{
		printf("error: texture path is NULL\n");
		return (0);
	}
	img->img = mlx_xpm_file_to_image(cube->mlx, img->path, &img->width,
			&img->height);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endiant);
	if (!img->addr)
		return (mlx_destroy_image(cube->mlx, img->img), 0);
	return (1);
}

int	init_textures_path(t_cub3d *cube)
{
	cube->textures.north.path = cube->no;
	cube->textures.south.path = cube->so;
	cube->textures.east.path = cube->ea;
	cube->textures.west.path = cube->we;
	if (!cube->textures.north.path || !cube->textures.south.path
		|| !cube->textures.east.path || !cube->textures.west.path)
		return (0);
	return (1);
}
