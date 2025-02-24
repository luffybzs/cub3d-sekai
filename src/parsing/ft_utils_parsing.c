/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:29:53 by ayarab            #+#    #+#             */
/*   Updated: 2025/02/24 12:40:03 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

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

int	ft_search_info(char *av1, t_cub3d *cube3d)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count += ft_fill_info(cube3d, line);
		if (count == -1 || count > 6)
			return (free(line), close(fd), EXIT_FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	if (!cube3d->we || !cube3d->so || !cube3d->ea || !cube3d->no || !cube3d->f
		|| !cube3d->c)
		return (close(fd), EXIT_FAILURE);
	return (close(fd), EXIT_SUCCESS);
}

int	ft_add_cardinal_points(char *str, t_cub3d *cube3d, int i)
{
	if (ft_add_no(str, cube3d, i) == -1 || ft_add_ea(str, cube3d, i) == -1)
		return (-1);
	if (ft_add_we(str, cube3d, i) == -1 || ft_add_so(str, cube3d, i) == -1)
		return (-1);
	if (ft_add_f(str, cube3d) == -1 || ft_add_c(str, cube3d) == -1)
		return (-1);
	if (ft_add_we(str, cube3d, i) == 1 || ft_add_so(str, cube3d, i) == 1)
		return (1);
	if (ft_add_no(str, cube3d, i) == 1 || ft_add_ea(str, cube3d, i) == 1)
		return (1);
	if (ft_add_f(str, cube3d) == 1 || ft_add_c(str, cube3d) == 1)
		return (1);
	return (0);
}
