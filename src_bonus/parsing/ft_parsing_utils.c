/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:01:40 by ayarab            #+#    #+#             */
/*   Updated: 2025/03/03 17:18:00 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d_bonus.h"

int	ft_check_av1(t_cub3d *cube3d)
{
	int	point;

	point = ft_strlen(cube3d->av1) - 4;
	if (ft_strlen(cube3d->av1) < 4)
		return (EXIT_FAILURE);
	if (ft_strcmp(&cube3d->av1[point], ".cub") != 0)
		return (EXIT_FAILURE);
	if (cube3d->av1[point - 1] == '/')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_fill_info(t_cub3d *cube3d, char *str)
{
	int	i;
	int	res;

	i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str)
	{
		res = ft_add_cardinal_points(str, cube3d, i);
		if (res == -1)
			return (-1);
		return (res);
	}
	return (0);
}

int	ft_add_door(char *str, t_cub3d *cube3d, int i)
{
	if (!ft_strncmp(str, "D", 1))
	{
		if (cube3d->door.path)
			return (-1);
		cube3d->door.path = ft_add_just_info(str, i + 1);
		if (!cube3d->door.path)
			return (-1);
		return (1);
	}
	return (EXIT_SUCCESS);
}

int	ft_add_cardinal_points(char *str, t_cub3d *cube3d, int i)
{
	if (ft_strncmp(str + i, "WE", 2) == 0)
		return (ft_add_we(str, cube3d, i));
	else if (ft_strncmp(str + i, "SO", 2) == 0)
		return (ft_add_so(str, cube3d, i));
	else if (ft_strncmp(str + i, "NO", 2) == 0)
		return (ft_add_no(str, cube3d, i));
	else if (ft_strncmp(str + i, "EA", 2) == 0)
		return (ft_add_ea(str, cube3d, i));
	else if (ft_strncmp(str + i, "C", 1) == 0)
		return (ft_add_c(str, cube3d));
	else if (ft_strncmp(str + i, "F", 1) == 0)
		return (ft_add_f(str, cube3d));
	else if (ft_strncmp(str + i, "D", 1) == 0)
		return (ft_add_door(str, cube3d, i));
	else
		return (0);
}