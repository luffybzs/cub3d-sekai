/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:31:23 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/11 21:28:22 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void init_struct_temp(t_map_info *data)
{
    t_cub3d cube;
    
    cube->NO = "./textures/colorstone.xpm";
    cube->SO = "./textures/bluestone.xpm";
    cube->WE = "./textures/greystone.xpm";
    cube->EA = " ./textures/wood.xpm";
    cube->S= "./textures/barrel.xpm";

    data->infos = cube;
    
    data->screen_width = 1920;
    data->screen_height = 1080;
    data->
    if (img_init(data))
        return (printf("echec init image\n"),1);    
}

int img_init(t_map_info *data)
{
    if (!load_single_image(data->mlx.mlx, &map->))
}

int load_single_image(void *mlx, void **img, char *path)
{
    int width;
    int height;

    *img = mlx_xpm_file_to_image(mlx, path, &width, &height);
    return (*img != NULL);
}