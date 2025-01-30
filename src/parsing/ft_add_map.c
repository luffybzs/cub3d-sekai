/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:58:05 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/30 21:49:46 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

int	ft_add_F(char *str, t_cub3d *cube3d)
{
	if (!ft_strncmp(str, "F", 1))
	{
		if (cube3d->F)
			return (-1);
		cube3d->F = ft_strdup(str + 1);
		if (!cube3d->F)
			return (-1);
		return (1);
	}
	return (EXIT_SUCCESS);
}
int	ft_add_C(char *str, t_cub3d *cube3d)
{
	if (!ft_strncmp(str, "C", 1))
	{
		if (cube3d->C)
			return (-1);
		cube3d->C = ft_strdup(str + 1);
		if (!cube3d->C)
			return (-1);
		return (1);
	}
	return (EXIT_SUCCESS);
}

int	ft_cmp_xpm(char *str, int i, char *cmp)
{
	int	j;

	j = 0;
	while (str[i] && cmp[j])
	{
		if (str[i] != cmp[j])
			return (str[i] - cmp[j]);
		i++;
		j++;
	}
	return (str[i] - cmp[j]);
}

int	ft_all_one(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] == '1')
		return (1);
	return (0);
}

int	ft_search_maps(char *av1, t_cub3d *cube3d)
{
	int		fd;
	char	*line;
	char	*res;

	res = NULL;
	fd = open(av1, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_all_one(line) || res)
		{
			res = ft_strjoin_free(res, line);
			if (!res)
				return (free(line), close(fd), EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	cube3d->all_maps = ft_split(res, '\n');
	if (!cube3d->all_maps)
		return (close(fd), free(res), EXIT_FAILURE);
	return (close(fd), free(res), EXIT_SUCCESS);
}
