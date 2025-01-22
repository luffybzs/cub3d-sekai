/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:28:56 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/22 18:01:28 by ayarab           ###   ########.fr       */
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
	return (close(fd), EXIT_SUCCESS);
}

int	ft_add_cardinal_points(char *str, t_cub3d *cube3d, int i)
{
	if (ft_add_WE(str, cube3d, i) == -1 || ft_add_SO(str, cube3d, i) == -1)
		return (-1);
	if (ft_add_NO(str, cube3d, i) == -1 || ft_add_EA(str, cube3d, i) == -1)
		return (-1);
	if (ft_add_F(str, cube3d) == -1 || ft_add_C(str, cube3d) == -1)
		return (-1);
	if (ft_add_WE(str, cube3d, i) == 1 || ft_add_SO(str, cube3d, i) == 1)
		return (1);
	if (ft_add_NO(str, cube3d, i) == 1 || ft_add_EA(str, cube3d, i) == 1)
		return (1);
	if (ft_add_F(str, cube3d) == -1 || ft_add_C(str, cube3d) == -1)
		return (1);
	return (0);
}
int ft_is_player(t_cub3d *cube3d, int j, int i)
{
	if (cube3d->all_maps[j - 1][i] == 'S' || cube3d->all_maps[j - 1][i] == 'N' || cube3d->all_maps[j - 1][i] == 'E' || cube3d->all_maps[j - 1][i] == 'W')
		return (1);
	if (cube3d->all_maps[j + 1][i] == 'S' || cube3d->all_maps[j + 1][i] == 'N' || cube3d->all_maps[j + 1][i] == 'E' || cube3d->all_maps[j + 1][i] == 'W')
		return (1);
	return (0);
}
int ft_is_floor(t_cub3d *cube3d, int j, int i)
{
	if (cube3d->all_maps[j - 1][i] == '0')
		return (1);
	if (cube3d->all_maps[j + 1][i] == '0')
		return (1);
	return (0);
}
int ft_is_wall(t_cub3d *cube3d, int j, int i)
{
	if (cube3d->all_maps[j - 1][i] == '1')
		return (1);
	if (cube3d->all_maps[j + 1][i] == '1')
		return (1);
	return (0);
}

int ft_check_line(char **tab)
{
	int i;
	int len;
	
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
	printf ("[$=%s]\n", tab[len]);
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



int ft_maps_is_good(t_cub3d *cube3d)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (ft_check_line(cube3d->all_maps) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (cube3d->all_maps[j])
	{
		while (cube3d->all_maps[j][i])
		{
			if (cube3d->all_maps[j][i] == '0')
			{
				if (!ft_is_floor(cube3d, j, i) && !ft_is_wall(cube3d,j, i) && !ft_is_player(cube3d, j, i))
					return (EXIT_FAILURE);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (EXIT_SUCCESS);
}










int	ft_fill_data(int ac, char **av, t_cub3d *cube3d)
{
	cube3d->ac = ac;
	cube3d->av1 = av[1];
	if (ft_check_av1(cube3d) == EXIT_FAILURE)
		return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
	if (ft_search_info(cube3d->av1, cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_search_maps(cube3d->av1, cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_fill_color(cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_maps_is_good(cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}