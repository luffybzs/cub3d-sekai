/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:28:56 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/24 12:03:25 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d_bonus.h"

int	ft_check_char(char c)
{
	if (c == 'N')
		return (EXIT_SUCCESS);
	if (c == 'S')
		return (EXIT_SUCCESS);
	if (c == 'E')
		return (EXIT_SUCCESS);
	if (c == 'W')
		return (EXIT_SUCCESS);
	if (c == '1')
		return (EXIT_SUCCESS);
	if (c == '0')
		return (EXIT_SUCCESS);
	if (c == 'D')
		return (EXIT_SUCCESS);
	if (c <= 32)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_is_all_good_char(t_cub3d *cube3d)
{
	int	i;
	int	j;

	j = 0;
	while (cube3d->all_maps[j])
	{
		i = 0;
		while (cube3d->all_maps[j][i])
		{
			if (ft_check_char(cube3d->all_maps[j][i]) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}

int	ft_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
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

int	ft_fill_data(int ac, char **av, t_cub3d *cube3d)
{
	cube3d->ac = ac;
	cube3d->av1 = av[1];
	if (ft_check_av1(cube3d) == EXIT_FAILURE)
		return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
	if (ft_search_info(cube3d->av1, cube3d) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nCan not find the info", 2), EXIT_FAILURE);
	if (ft_search_maps(cube3d->av1, cube3d) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nMap Not Found", 2), EXIT_FAILURE);
	if (ft_fill_color(cube3d) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nRGB Is Not Good", 2), EXIT_FAILURE);
	if (ft_is_all_good_char(cube3d) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nMap Invalid Char", 2), EXIT_FAILURE);
	if (ft_maps_is_good(cube3d) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nMap Is Not Close", 2), EXIT_FAILURE);
	if (ft_check_player(cube3d) == EXIT_FAILURE)
		return (ft_putendl_fd("Error\nNot Or Too Many Player", 2),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
