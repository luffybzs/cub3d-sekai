/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:31:23 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/12 17:28:44 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_cub3d(t_cub3d *cube)
{
	(void)cube;
	ft_memset(cube, 0, sizeof(t_cub3d));
	cube->screen_width = 1920;
	cube->screen_height = 1080;
	
    if (init_mlx(cube) || !cube->mlx || !cube->win)
		return (printf("fail to init MLX\n"),cleanup(cube),1);

	if (!init_textures(cube))
		return (printf("fail to init textures\n"),cleanup(cube), 1);

	return (0);
}

int	init_textures(t_cub3d *cube)
{
	if (!load_texture(cube->mlx, &cube->textures.north,
			"./textures/colorstone.xpm")) // a modifie plus tard avec le parsing
		return (0);
	if (!load_texture(cube->mlx, &cube->textures.south,
			"./textures/bluestone.xpm")) // a modifie plus tard avec le parsing
	{
		mlx_destroy_image(cube->mlx, cube->textures.north.img);
		mlx_destroy_image(cube->mlx, cube->textures.south.img);
		return (0);
	}
        if (!load_texture(cube->mlx, &cube->textures.east, " ./textures/wood.xpm"))
    {
        mlx_destroy_image(cube->mlx, cube->textures.north.img);
        mlx_destroy_image(cube->mlx, cube->textures.south.img);
        mlx_destroy_image(cube->mlx, cube->textures.west.img);
        return (0);
    }
    return (1);
}

int load_texture(void *mlx, t_img *img, char *path)
{
    img->img= mlx_xpm_file_to_image(mlx,path, &img->width,&img->height);
        if (!img->img)
            return (0);
    
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    if (!img->addr)
        return (mlx_destroy_image(mlx,img->img),0);
    return (1);
}
