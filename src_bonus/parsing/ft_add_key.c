/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:12:59 by ayarab            #+#    #+#             */
/*   Updated: 2025/03/03 17:14:08 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d_bonus.h"

int	ft_add_key(t_cub3d *cube3d, int fd)
{
	char	*line;
	int		count;
	int		tmp;

	line = get_next_line(fd);
	count = 0;
	while (line && count != 7)
	{
		// line = skip space
		if (ft_check_key(line) == EXIT_FAILURE)
			return (free(line), EXIT_FAILURE);
		tmp = ft_fill_info(cube3d, line);
		if (tmp == -1)
			return (free(line), EXIT_FAILURE);
		count += tmp;
		free(line);
		line = get_next_line(fd);
	}
	if (!cube3d->we || !cube3d->so || !cube3d->ea || !cube3d->no || !cube3d->f
		|| !cube3d->c)
		return (close(fd), EXIT_FAILURE);
	if (ft_strdup_maps(cube3d, fd, line) == 1)
		return (close(fd), 1);
	return (0);
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

int	ft_strdup_maps(t_cub3d *cube3d, int fd, char *line)
{
	char	*res;

	res = NULL;
	while (line)
	{
		if (!res && ft_line_space(line) == 1)
			return (free(line), 1);
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
	return (close(fd), free(res), free(line), EXIT_SUCCESS);
}

int	ft_check_key(char *line)
{
	if (!line)
		return (EXIT_FAILURE);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (EXIT_SUCCESS);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (EXIT_SUCCESS);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (EXIT_SUCCESS);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (EXIT_SUCCESS);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (EXIT_SUCCESS);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (EXIT_SUCCESS);
	if (ft_strncmp(line, "D", 1) == 0)
		return (EXIT_SUCCESS);
	if (ft_strncmp(line, "\n", 1) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_search_info(char *av1, t_cub3d *cube3d)
{
	int fd;

	fd = open(av1, O_RDONLY);
	if (fd == -1)
		(ft_putendl_fd("Error\nFail Open", 2), exit(1));
	if (ft_add_key(cube3d, fd) == 1)
		return (close(fd), 1);
	return (close(fd), EXIT_SUCCESS);
}