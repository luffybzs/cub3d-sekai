/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:35:33 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/11 16:14:22 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_error(t_cub3d *cube, char *msg, int error_code)
{
	//choisir si garder error_code
	//centralisation de la gestion des erreur
	ft_putendl_fd(msg, 2);
	cleanup(cube);
	exit(error_code); //garder exit ou prendre un simple return
}

void	test_print(char **map)
{
	int	i;
	int	j;

	i = 0;
	printf("\n=== Map Content ===\n");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("[%c]", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
void	calculate_distance(t_raycast *ray)
{
	//calcul de la distance perpendiculaire
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
