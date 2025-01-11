/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:30:08 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/11 16:27:36 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_mlx(t_map_info *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (ft_putendl_fd("Error: Failed to initialize MLX", 2), 1);
	// gerer la taille de l ecran ? voir so_long
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->screen_height,
			data->screen_width, "Cub3D-Sekai");
  if (!data->mlx.win)
    		return (ft_putendl_fd("Error: Failed to initialize MLX", 2),mlx_destroy_display(data->mlx.mlx), 1);
  return (0);
}