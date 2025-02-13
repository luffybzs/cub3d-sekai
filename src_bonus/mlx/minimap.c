/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:42:05 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/13 17:14:47 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	put_pixel_to_minimap(t_cub3d *cube, int x, int y, int color)
{
	char	*dst;
	int		pos;

	if (x < 0 || x >= cube->screen_width || y < 0 || y >= cube->screen_height)
		return ;
	pos = (y * cube->buffer.size_line) + (x * (cube->buffer.bits_per_pixel
				/ 8));
	dst = cube->buffer.addr + pos;
	*(unsigned int *)dst = color;
}

void	draw_block(t_cub3d *cube, int x, int y, int color)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	start_x = x * BLOCK_SIZE;
	start_y = y * BLOCK_SIZE;
	i = 0;
	while (i < BLOCK_SIZE)
	{
		j = 0;
		while (j < BLOCK_SIZE)
		{
			put_pixel_to_minimap(cube, start_x + j, start_y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_player_block(t_cub3d *cube)
{
	int	i;
	int	j;
	int	player_x;
	int	player_y;

	player_x = cube->player.pos_x * BLOCK_SIZE;
	player_y = cube->player.pos_y * BLOCK_SIZE;
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			put_pixel_to_minimap(cube, player_x + j, player_y + i, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_cub3d *cube)
{
	int	x;
	int	y;

	y = 0;
	while (y < cube->map_height && cube->all_maps[y])
	{
		x = 0;
		while (x < cube->map_width && cube->all_maps[y][x])
		{
			if (cube->all_maps[y][x] == '1')
				draw_block(cube, x, y, 0xFFFFFF);
			else if (cube->all_maps[y][x] == '0')
				draw_block(cube, x, y, 0x000000);
			else if (cube->all_maps[y][x] == 'D')
				draw_block(cube, x, y, 0x660000);
			else if (cube->all_maps[y][x] == 'O')
				draw_block(cube, x, y, 0x274E13);
			x++;
		}
		y++;
	}
	draw_player_block(cube);
}
