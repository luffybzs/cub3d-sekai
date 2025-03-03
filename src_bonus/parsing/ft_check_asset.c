/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_asset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:44:11 by ayarab            #+#    #+#             */
/*   Updated: 2025/03/03 17:25:43 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d_bonus.h"

int	ft_atoi_rgb(char *str, int start, int end)
{
	int	res;

	res = 0;
	while (start < end)
	{
		res *= 10;
		res += str[start] - 48;
		if (res > 255)
			return (-1);
		start++;
	}
	return (res);
}

void	ft_fail_free(t_cub3d *cube3d)
{
	if (cube3d->ea)
		free(cube3d->ea);
	if (cube3d->no)
		free(cube3d->no);
	if (cube3d->we)
		free(cube3d->we);
	if (cube3d->so)
		free(cube3d->so);
	if (cube3d->f)
		free(cube3d->f);
	if (cube3d->c)
		free(cube3d->c);
	if (cube3d->door.path)
		free(cube3d->door.path);
	if (cube3d->all_maps)
		ft_free_2d(cube3d->all_maps);
	return ;
}

void	ft_init_pos(t_cub3d *cube3d, int i, int j)
{
	cube3d->direction = cube3d->all_maps[j][i];
	cube3d->x_spwan_p = i;
	cube3d->y_spwan_p = j;
}

int	ft_fill_space_in_wall(t_cub3d *cube3d)
{
	int	i;
	int	j;

	j = 0;
	if (!cube3d->all_maps)
		return (EXIT_FAILURE);
	while (cube3d->all_maps[j])
	{
		i = 0;
		while (cube3d->all_maps[j][i])
		{
			if (cube3d->all_maps[j][i] == 32)
				cube3d->all_maps[j][i] = '1';
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}

char	*skip_space(char *line)
{
	char	*temp;

	if (!line)
		return (NULL);
	temp = line;
	while (*line && *line <= 32 && *line != '\n')
		++line;
	line = ft_strdup(line);
	free(temp);
	return (line);
}
