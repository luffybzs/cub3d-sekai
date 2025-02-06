/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:31:23 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/06 19:13:40 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	init_cub3d(t_cub3d *cube)
{
	if (!cube->all_maps)
		return (1);
	//calcule de la taille de la map
	cube->map_height = 0;
	while (cube->all_maps[cube->map_height])
		cube->map_height++;
	if (cube->map_height > 0)
		cube->map_width = ft_strlen(cube->all_maps[0]);
	else
		return (1);
	if (!init_textures_path(cube))
		return (printf("fail to init paths\n"), 1);
	//ici joindre le parsing (trouver position ainsi qu orientation)
	//  test_print(cube->all_maps);

	init_player(cube);
	if (init_mlx(cube) || !cube->mlx || !cube->win)
		return (printf("fail to init MLX\n"), 1);
	cube->z_buffer = malloc(sizeof(double) * cube->screen_width);
	if (!cube->z_buffer)
		return (cleanup(cube), 1);
	if (!open_images(cube))
		return (printf("fail to init textures\n"), 1);
	// printf("arriver dans init cubAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	return (0);
}

int	open_images(t_cub3d *cube)
{
	// creee un buffer une toile blanche qui va permetttre apres de mettre le rendu
	if (!init_buffer(cube))
		return (0);
	// initialisation des textures
	if (!ft_init_img(cube, &cube->textures.north) ||
		!ft_init_img(cube, &cube->textures.south) ||
		!ft_init_img(cube, &cube->textures.west) ||
		!ft_init_img(cube, &cube->textures.east))
		return (0);
	if (cube->door.path)
			if(!ft_init_img(cube,&cube->door))
				return (0);
	// if(!init_mini_map(cube))
	// 	return (0);
	printf("south = %s\nnorth = %s\neast=%s\nwest=%s\ndoor=%s\n",cube->textures.south.path, cube->textures.north.path,cube->textures.east.path,cube->textures.west.path,cube->door.path);
	return (1);
}
int	init_buffer(t_cub3d *cube)
{
	if (!cube->mlx)
		return (0);
	cube->buffer.img = mlx_new_image(cube->mlx, cube->screen_width,
										cube->screen_height);
										//creer une image vide principe de la toile vierge
	if (!cube->buffer.img)
		return (0);
	cube->buffer.addr = mlx_get_data_addr(cube->buffer.img,
											&cube->buffer.bits_per_pixel,
											&cube->buffer.size_line,
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
	cube->textures.north.path = cube->NO;
	cube->textures.south.path = cube->SO;
	cube->textures.east.path = cube->EA;
	cube->textures.west.path = cube->WE;
	if (!cube->textures.north.path || !cube->textures.south.path
		|| !cube->textures.east.path || !cube->textures.west.path)
		return (0);
	return (1);
}


// int	load_texture(void *mlx, t_img *img, char *path)
// {
// 	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
// 	if (!img->img)
// 		return (0);
// 	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
// 			&img->line_length, &img->endiant);
// 	if (!img->addr)
// 		return (mlx_destroy_image(mlx, img->img), 0);
// 	return (1);
// }

void	init_player(t_cub3d *cube)
{
 // recuperation du parsing en cours
	// position intiale
	cube->player.pos_x = cube->x_spwan_p + 0.5;
	cube->player.pos_y = cube->y_spwan_p + 0.5;

	if (cube->direction == 'N')
	{
		cube->player.dir_x =0;
		cube->player.dir_y = -1;
		cube->player.plane_x = 0.66;
		cube->player.plane_y = 0;
	}
	if (cube->direction == 'S')
	{
		cube->player.dir_x =0;
		cube->player.dir_y = 1;
		cube->player.plane_x = -0.66;
		cube->player.plane_y = 0;
	}
	if (cube->direction == 'E')
	{
		cube->player.dir_x =1;
		cube->player.dir_y = 0;
		cube->player.plane_x = 0;
		cube->player.plane_y = 0.66;
	}
	if (cube->direction == 'W')
	{
		cube->player.dir_x =-1;
		cube->player.dir_y = 0;
		cube->player.plane_x = 0;
		cube->player.plane_y = -0.66;
	}
}
