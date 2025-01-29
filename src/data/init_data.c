/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:31:23 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/29 17:19:55 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_cub3d(t_cub3d *cube)
{
	cube->map = create_test_map();//temporaire
	if (!cube->map)
		return (1);
	cube->map_height = 0;
	//calcule de la taille de la map
	while (cube->map[cube->map_height])
		cube->map_height++;
	if (cube->map_height > 0)
		cube->map_width = ft_strlen(cube->map[0]);
	else
		return (cleanup(cube),1);

	if (!init_textures_path(cube))// a remplacer 
		return (printf("fail to init paths\n"), cleanup(cube), 1);
	
	init_player(cube);
	
	if (init_mlx(cube) || !cube->mlx || !cube->win)
		return (printf("fail to init MLX\n"), cleanup(cube), 1);
	cube->z_buffer = malloc(sizeof(double) * cube->screen_width);
	if (!cube->z_buffer) 
		return (cleanup(cube), 1);
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
	if (!cube->mlx)
        return (0);
	cube->buffer.img = mlx_new_image(cube->mlx, cube->screen_width,
			cube->screen_height);//creer une image vide principe de la toile vierge
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

int	init_textures_path(t_cub3d *cube)
{// a modifier et recuperer les donnees du parsing
	cube->textures.north.path = "./textures/north.xpm";
	cube->textures.south.path = "./textures/south.xpm";
	cube->textures.east.path = "./textures/east.xpm";
	cube->textures.west.path = "./textures/west.xpm";
	if (!cube->textures.north.path || !cube->textures.south.path
		|| !cube->textures.east.path || !cube->textures.west.path)
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
{// a modifier et recuperer les donnees du parsing
	// position intiale
	cube->player.pos_x = 6.0; // ajout des differentes positions du joueur
	cube->player.pos_y = 3.0;
	// vecteur de direction
	// en fonction de l orientation choisir l angle
	cube->player.dir_x = -1.0; // direction nord
	cube->player.dir_y = 0;
	// negatif car origine (0;0) en haut a gauche de la map
	//plan de la camera important dans le raycasting
	cube->player.plane_x = 0.0;
	cube->player.plane_y = 0.66;
}

/* 
if (cube->player->direction = 'N')
{
	cube->player.dir_x =0;
	cube->player.dir_y = -1;
	cube->player.plane_x = 0.66;
	cube->player.plane_y = 0;
}
if (cube->player->direction = 'S')
{
	cube->player.dir_x =0;
	cube->player.dir_y = 1;
	cube->player.plane_x = -0.66;
	cube->player.plane_y = 0;
}
if (cube->player->direction = 'E')
{
	cube->player.dir_x =1;
	cube->player.dir_y = 0;
	cube->player.plane_x = 0;
	cube->player.plane_y = 0.66;
}
if (cube->player->direction = 'N')
{
	cube->player.dir_x =-1;
	cube->player.dir_y = 0;
	cube->player.plane_x = 0;
	cube->player.plane_y = -0.66;
}
*/

//temporaire ajout d une map pour le test
char	**create_test_map(void)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * 8);
	if (!map)
		return (NULL);
	map[0] = ft_strdup("111111111111");
	map[1] = ft_strdup("100000000001");
	map[2] = ft_strdup("111111011111");
	map[3] = ft_strdup("100000N00001");
	map[4] = ft_strdup("100000000001");
	map[5] = ft_strdup("100000000001");
	map[6] = ft_strdup("111111111111");
	map[7] = NULL;
	i = 0;
	while (i < 7)
	{
		if (!map[i])
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}
