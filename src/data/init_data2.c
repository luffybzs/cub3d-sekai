/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:43:59 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/11 15:44:33 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	load_texture(void *mlx, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endiant);
	if (!img->addr)
		return (mlx_destroy_image(mlx, img->img), 0);
	return (1);
}

void	init_player(t_cub3d *cube)
{
	// position intiale
	cube->player.pos_x = cube->x_spwan_p + 0.5;
	cube->player.pos_y = cube->y_spwan_p + 0.5;
	// +0.5 pour centrer l apparition du personnage
	if (cube->direction == 'N')
	{
		cube->player.dir_x = 0;
		cube->player.dir_y = -1;
		cube->player.plane_x = 0.66;
		cube->player.plane_y = 0;
	}
	if (cube->direction == 'S')
	{
		cube->player.dir_x = 0;
		cube->player.dir_y = 1;
		cube->player.plane_x = -0.66;
		cube->player.plane_y = 0;
	}
	init_player2(cube);
}

void	init_player2(t_cub3d *cube)
{
	if (cube->direction == 'E')
	{
		cube->player.dir_x = 1;
		cube->player.dir_y = 0;
		cube->player.plane_x = 0;
		cube->player.plane_y = 0.66;
	}
	if (cube->direction == 'W')
	{
		cube->player.dir_x = -1;
		cube->player.dir_y = 0;
		cube->player.plane_x = 0;
		cube->player.plane_y = -0.66;
	}
}
