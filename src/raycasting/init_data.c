/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:31:23 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/19 14:27:25 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_cub3d(t_cub3d *cube)
{
	(void)cube;
	ft_memset(cube, 0, sizeof(t_cub3d));
	
	if(!init_textures_path(cube))
		return (printf("fail to init paths\n"),cleanup(cube),1);
	
	init_player(cube);
	if (init_mlx(cube) || !cube->mlx || !cube->win)
		return (printf("fail to init MLX\n"), cleanup(cube), 1);
	if (!open_images(cube))
		return (printf("fail to init textures\n"), cleanup(cube), 1);
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
	return (1);
}

int	init_buffer(t_cub3d *cube)
{
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
	    printf("Loading texture from path: %s\n", img->path);
// ici ca plante a verifier pourquoi si les xpm sont bien converti ou pas 
	img->img = mlx_xpm_file_to_image(cube->mlx, img->path, &img->width,&img->height);
	if (!img->img)//ici l img bug verifier l initialisation..
		return (0);
		
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endiant);
	if (!img->addr)
		return (mlx_destroy_image(cube->mlx, img->img),0);
		
	return (1);
}
int	init_textures_path(t_cub3d *cube)
{
	cube->textures.north.path ="../../textures/north.xpm" ;
	cube->textures.south.path = "../../textures/south.xpm";
	cube->textures.east.path = "../../textures/east.xpm";
	cube->textures.west.path = "../../textures/west.xpm";

	if (!cube->textures.north.path || !cube->textures.south.path || !cube->textures.east.path || !cube->textures.west.path)
		return (0);
	
	return (1);
}


int	init_textures(t_cub3d *cube)
{
	(void)cube;
	// if (!load_texture(cube->mlx, &cube->textures.north,
	// 					"./textures/colorstone.xpm"))
	// 						// a modifie plus tard avec le parsing
	// 	return (0);
	// if (!load_texture(cube->mlx, &cube->textures.south,
	// 					"./textures/bluestone.xpm"))
	// 						// a modifie plus tard avec le parsing
	// {
	// 	mlx_destroy_image(cube->mlx, cube->textures.north.img);
	// 	mlx_destroy_image(cube->mlx, cube->textures.south.img);
	// 	return (0);
	// }
	// if (!load_texture(cube->mlx, &cube->textures.east,
				// "./textures/wood.xpm"))
	// {
	// 	mlx_destroy_image(cube->mlx, cube->textures.north.img);
	// 	mlx_destroy_image(cube->mlx, cube->textures.south.img);
	// 	mlx_destroy_image(cube->mlx, cube->textures.west.img);
	// 	return (0);
	// }
	// return (1);
	return (1);
}

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
	cube->player.pos_x = 6.0; // ajout des differentes positions du joueur
	cube->player.pos_y = 3.0;
	// vecteur de direction
	// en fonction de l orientation choisir l angle
	cube->player.dir_x = 0.0;  // direction nord
	cube->player.dir_y = -1.0;
		// negatif car origine (0;0) en haut a gauche de la map
	//plan de la camera important dans le raycasting
	cube->player.plane_x = 0.66;
	cube->player.plane_y = 0.0;
}

/* 
if (cube->"position " = 'N')
{
	cube->player.dir_x =0;
	cube->player.dir_y = -1;
	cube->player.plane_x = 0.66;
	cube->player.plane_y = 0;
}
if (cube->"position " = 'S')
{
	cube->player.dir_x =0;
	cube->player.dir_y = 1;
	cube->player.plane_x = -0.66;
	cube->player.plane_y = 0;
}
if (cube->"position " = 'E')
{
	cube->player.dir_x =1;
	cube->player.dir_y = 0;
	cube->player.plane_x = 0;
	cube->player.plane_y = 0.66;
}
if (cube->"position " = 'N')
{
	cube->player.dir_x =-1;
	cube->player.dir_y = 0;
	cube->player.plane_x = 0;
	cube->player.plane_y = -0.66;
}
*/