/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parsing2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:33:49 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/20 14:45:53 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

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

int	ft_ft(t_cub3d *cube3d, int i, int j)
{
	if (cube3d->all_maps[j][i] == 'W')
		return (1);
	if (cube3d->all_maps[j][i] == 'S')
		return (1);
	if (cube3d->all_maps[j][i] == 'E')
		return (1);
	if (cube3d->all_maps[j][i] == 'N')
		return (1);
	if (cube3d->all_maps[j][i] == '0')
		return (1);
	if (cube3d->all_maps[j][i] == '1')
		return (1);
	return (0);
}

int	ft_is_good(t_cub3d *cube3d, int j, int i)
{
	if (!ft_ft(cube3d, i, j - 1))
		return (EXIT_FAILURE);
	if (!ft_ft(cube3d, i, j + 1))
		return (EXIT_FAILURE);
	if (!ft_ft(cube3d, i + 1, j))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
