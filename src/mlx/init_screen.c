/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:30:08 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/01/11 17:45:37 by wdaoudi-         ###   ########.fr       */
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
		return (ft_putendl_fd("Error: Failed to initialize MLX", 2),
			mlx_destroy_display(data->mlx.mlx), 1);
	return (0);
}

int	close_window(t_map_info *data)
{
	cleanup(data);
	exit(0);
}

void	cleanup(t_map_info *data)
{
	if (data->mlx.win)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		data->mlx.win = NULL;
	}
	// free_images ulterieurment
	if (data->mlx.mlx)
	{
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
		data->mlx.mlx = NULL;
	}
	// free_map(data) la future copie;
}