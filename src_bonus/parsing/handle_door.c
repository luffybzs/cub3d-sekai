/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:23:39 by wdaoudi-          #+#    #+#             */
/*   Updated: 2025/02/06 14:38:16 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_check_door(t_cub3d *cube3d)
{
	int i = 0;
	int j = 0;
	bool door = false;

	while (cube3d->all_maps[j])
	{
		i = 0;
		while (cube3d->all_maps[j][i])
		{
			if ((cube3d->all_maps[j][i]) == 'D')
			{
				
				cube3d->x_door = i;
				cube3d->y_door = j;
			}
			i++;
		}
		j++;
	}
	if (player == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
} 
/*
recuperer les coordonnees ?
*/