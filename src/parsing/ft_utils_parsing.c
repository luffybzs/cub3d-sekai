/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:29:53 by ayarab            #+#    #+#             */
/*   Updated: 2025/03/03 17:09:32 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"
#include <stdio.h>

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

int	ft_maps_is_good(t_cub3d *cube3d)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ft_check_line(cube3d->all_maps) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (cube3d->all_maps[j])
	{
		if (ft_skip(cube3d->all_maps, j) == -1)
			return (EXIT_FAILURE);
		while (cube3d->all_maps[j][i])
		{
			if (cube3d->all_maps[j][i] == '0'
				|| ft_player(cube3d->all_maps[j][i]) == 0)
			{
				if (ft_is_good(cube3d, j, i) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_player(t_cub3d *cube3d)
{
	int		i;
	int		j;
	bool	player;

	j = 0;
	player = false;
	while (cube3d->all_maps[j])
	{
		i = 0;
		while (cube3d->all_maps[j][i])
		{
			if (ft_player(cube3d->all_maps[j][i]) == EXIT_SUCCESS)
			{
				if (player == true)
					return (EXIT_FAILURE);
				ft_init_pos(cube3d, i, j);
				player = true;
			}
			i++;
		}
		j++;
	}
	if (player == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_line_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] > 32 && line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_search_info(char *av1, t_cub3d *cube3d)
{
	int	fd;

	fd = open(av1, O_RDONLY);
	if (fd == -1)
		(ft_putendl_fd("Error\nFail Open", 2), exit(1));
	if (ft_add_key(cube3d, fd) == 1)
		return (close(fd), 1);
	return (close(fd), EXIT_SUCCESS);
}
