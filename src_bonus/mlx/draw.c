/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:01:34 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/31 14:42:24 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	calculate_draw_points(t_cub3d *cube, t_raycast *ray, t_draw *draw)
{
	// Calcul de la hauteur de la ligne à dessiner
	draw->line_height = (int)(cube->screen_height / ray->wall_dist);
	// Calcul des points de début et de fin
	draw->start = -draw->line_height / 2 + cube->screen_height / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = draw->line_height / 2 + cube->screen_height / 2;
	if (draw->end >= cube->screen_height)
		draw->end = cube->screen_height - 1;
}

int	draw_background(t_cub3d *cube)
{
	int	*buffer;
	int ceiling_color;
	int floor_color;
	int half_screen;
	int i;
	// definition de la couleur == (red << 16)|(green << 8)|(blue)
	// les 8 bits les plus significatif correspondent au alpha == transparence
	ceiling_color = (cube->C_R << 16) | (cube->C_G << 8) | cube->C_B;
	floor_color = (cube->F_R << 16) | (cube->F_G << 8) | cube->F_B;
	buffer = (int *)cube->buffer.addr;
	if (!buffer)
		return(printf("Error: empty buffer\n"),1);
	half_screen = (cube->screen_width * cube->screen_height) / 2;
	i = 0;
	while (i < half_screen)
	{
		buffer[i] = ceiling_color;
		i ++;
	}
	while (i < cube->screen_width * cube->screen_height)
	{
		buffer[i] = floor_color;
		i ++;
	}
	return (0);
}
