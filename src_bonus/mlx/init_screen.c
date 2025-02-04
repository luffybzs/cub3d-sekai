/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:30:08 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/04 15:01:08 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	init_mlx(t_cub3d *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_putendl_fd("Error: Failed to initialize MLX", 2), 1);
	mlx_get_screen_size(data->mlx, &data->screen_height, &data->screen_width);
	if (data->screen_height > 1080 || data->screen_height <= 0)
		data->screen_height = 1080;
	if (data->screen_width > 1920 || data->screen_width <= 0)
		data->screen_width = 1920;
	data->win = mlx_new_window(data->mlx, data->screen_width,
			data->screen_height, "Cub3D-Sekai");
	if (!data->win)
		return (ft_putendl_fd("Error: Failed to initialize MLX", 2),
				mlx_destroy_display(data->mlx),
				1);
	return (0);
}

int	close_window(t_cub3d *data)
{
	cleanup(data);
	exit(0);
	return (0);
}

void	cleanup(t_cub3d *cube)
{
	if (cube->textures.north.img)
		mlx_destroy_image(cube->mlx, cube->textures.north.img);
	if (cube->textures.south.img)
		mlx_destroy_image(cube->mlx, cube->textures.south.img);
	if (cube->textures.west.img)
		mlx_destroy_image(cube->mlx, cube->textures.west.img);
	if (cube->textures.east.img)
		mlx_destroy_image(cube->mlx, cube->textures.east.img);
	if (cube->win)
		mlx_destroy_window(cube->mlx, cube->win);
	if (cube->mlx)
	{
		mlx_destroy_display(cube->mlx);
		free(cube->mlx);
	}
	if (cube->z_buffer)
	{
		free(cube->z_buffer);
		cube->z_buffer = NULL;
	}
}
