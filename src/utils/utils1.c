/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:35:33 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/03/04 16:44:48 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_error(t_cub3d *cube, char *msg, int error_code)
{
	ft_putendl_fd(msg, 2);
	cleanup(cube);
	exit(error_code);
}

int	find_width(t_cub3d *cube)
{
	int	i;
	int	cmp;

	i = 0;
	cube->map_width = 0;
	if (cube->map_height <= 0)
		return (1);
	while (i <= cube->map_height)
	{
		cmp = ft_strlen(cube->all_maps[i]);
		if (cmp > cube->map_width)
			cube->map_width = cmp;
		i++;
	}
	return (0);
}

void	calculate_distance(t_raycast *ray)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

void	intersection(t_cub3d *cube, t_raycast *ray)
{
	(void)cube;
	ray->side_dist_x += ray->delta_dist_x;
	ray->map_x += ray->step_x;
	ray->side = 0;
}

void	intersection2(t_cub3d *cube, t_raycast *ray)
{
	(void)cube;
	ray->side_dist_y += ray->delta_dist_y;
	ray->map_y += ray->step_y;
	ray->side = 1;
}
