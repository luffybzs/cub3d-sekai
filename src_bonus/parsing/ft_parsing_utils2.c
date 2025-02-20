/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:56:46 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/20 15:09:36 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d_bonus.h"

int	ft_check_line(char **tab)
{
	int	i;
	int	len;

	len = (ft_strlen_2d(tab) - 1);
	i = 0;
	while (tab[0][i] && tab[0][i] <= 32)
		i++;
	while (tab[0][i])
	{
		if (tab[0][i] != '1' && tab[0][i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (tab[len][i] && tab[len][i] <= 32)
		i++;
	while (tab[len][i])
	{
		if (tab[len][i] != '1' && tab[len][i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
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
	if (cube3d->all_maps[j][i] == 'D')
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

int	ft_skip(char **tab, int j)
{
	int	i;

	i = 0;
	while (tab[j][i] && tab[j][i] <= 32)
		i++;
	if (tab[j][i] == '1')
		return (0);
	return (-1);
}

int	ft_maps_is_good(t_cub3d *cube3d)
{
	int	i;
	int	j;

	j = 1;
	if (ft_check_line(cube3d->all_maps) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (cube3d->all_maps[j])
	{
		i = 0;
		if (ft_skip(cube3d->all_maps, j) == -1)
			return (EXIT_FAILURE);
		while (cube3d->all_maps[j][i])
		{
			if (cube3d->all_maps[j][i] == '0'
				|| ft_player(cube3d->all_maps[j][i]) == 0
				|| cube3d->all_maps[j][i] == 'D')
			{
				if (ft_is_good(cube3d, j, i) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}
