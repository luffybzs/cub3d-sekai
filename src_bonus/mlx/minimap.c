/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:42:05 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/04 17:36:24 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	init_mini_map(t_cub3d *cube)
{
	cube->minimap.img = mlx_new_image(cube->mlx, MINIMAP_WIDTH /*cube->screen_width * (MINIMAP_SCALE)*/,
			/*cube->screen_height * (MINIMAP_SCALE)*/MINIMAP_HEIGHT);
    cube->width = cube->screen_height * MINIMAP_SCALE;
    cube->height = cube->screen_width * MINIMAP_SCALE;
	cube->minimap.addr = mlx_get_data_addr(cube->minimap.img,
			&cube->minimap.bits_per_pixel, &cube->minimap.size_line,
			&cube->minimap.endiant);
	if (!cube->minimap.img)
		return (0);
	return (1);
}

void	draw_map_pixel(t_cub3d *cube, int x, int y, int color)
{
	int screen_x;
	int screen_y;
	int offset_x;

	screen_y = y /*MINIMAP_SCALE*/;
	screen_x = x /* MINIMAP_SCALE*/;
	offset_x = (cube->screen_width - MINIMAP_SCALE) / 2;

	// proteger les limites + ajout des couleurs
	if (screen_x >= 0 && screen_x < cube->width && screen_y >= 0
		&& screen_y < cube->height)
	{
		int *buffer = (int *)cube->buffer.addr;
		int pixel_pos = (screen_y * cube->screen_width) + (screen_x + offset_x);

		if (pixel_pos >= 0 && pixel_pos < (cube->screen_width
				* cube->screen_height))
			buffer[pixel_pos] = color;
	}
}

void draw_minimap(t_cub3d *cube)//ajouter des bords  a la map
{
    int x;
    int y;
    
    y = 0;
    while (y < cube->map_height)
    {
        x = 0;
        while (x < cube->map_width)
        {
            if (cube->all_maps[y][x] == '1')
                draw_map_pixel(cube,x,y,0xFFFFFF);
            else if(cube->all_maps[y][x] == '0')
               draw_map_pixel(cube,x,y,0x404040);
            else if(cube->all_maps[y][x] == 'D')
                draw_map_pixel(cube,x,y,0x660000);
            x++;
        }
        y++;
    }
    draw_map_pixel(cube,cube->player.pos_x, cube->player.pos_y,0xFFFF00);
}