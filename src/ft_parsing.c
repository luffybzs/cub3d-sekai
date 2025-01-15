/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:28:56 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/15 23:21:38 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"



int ft_check_av1(t_cub3d *cube3d)
{
	int point;

	point = ft_strlen(cube3d->av1) - 4;
	if (ft_strlen(cube3d->av1) < 4)
		return (EXIT_FAILURE);
	if (ft_strcmp(&cube3d->av1[point], ".cub") != 0)
		return (EXIT_FAILURE);
	if (cube3d->av1[point - 1] == '/')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int ft_search_info(char *av1, t_cub3d *cube3d)
{
    int fd;
    char *line;
    char *res;

    fd = open(av1, O_RDONLY);
    if (fd == -1)
        return (EXIT_FAILURE);
    res = ft_strdup("");
    if (!res)
        return (EXIT_FAILURE);
    line = get_next_line(fd);
    while (line)
    {
        res = ft_strjoin_free(res, line);
        if (!res)
            return (free(line), EXIT_FAILURE);
        free(line);
        line = get_next_line(fd);
    }
    cube3d->all_maps = ft_split(res, '\n');
    if (!cube3d->all_maps)
        return (free(res), EXIT_FAILURE);
    return (free(res), EXIT_SUCCESS);
}

int ft_search_cardinal_points(t_cub3d *cube3d)
{
	int j;

	j = 0;
	while(cube3d->all_maps[j])
	{
		if (ft_strnstr(cube3d->all_maps[j], "NO", 2) != NULL)
			cube3d->NO = ft_strdup(cube3d->all_maps[j]);
		if (ft_strnstr(cube3d->all_maps[j], "SO", 2) != NULL)
			cube3d->SO = ft_strdup(cube3d->all_maps[j]);
		if (ft_strnstr(cube3d->all_maps[j], "WE", 2) != NULL)
			cube3d->WE = ft_strdup(cube3d->all_maps[j]);
		if (ft_strnstr(cube3d->all_maps[j], "EA", 2) != NULL)
			cube3d->EA = ft_strdup(cube3d->all_maps[j]);
		if (ft_strnstr(cube3d->all_maps[j], "C", 1) != NULL)
			cube3d->C = ft_strdup(cube3d->all_maps[j]);
		if (ft_strnstr(cube3d->all_maps[j], "F", 1) != NULL)
			cube3d->F = ft_strdup(cube3d->all_maps[j]);
		j++;
	}
	if (!cube3d->NO || !cube3d->SO || !cube3d->WE || !cube3d->EA || !cube3d->C || !cube3d->F)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int ft_fill_data(int ac, char **av, t_cub3d *cube3d)
{
    cube3d->ac = ac;
    cube3d->av1 = av[1];
    if (ft_check_av1(cube3d) == EXIT_FAILURE)
		return (ft_putstr_fd("Error\n", 2) ,EXIT_FAILURE);
	if (ft_search_info(cube3d->av1, cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_search_cardinal_points(cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_fill_color(cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if ()
	//if (ft_search_just_map(cube3d) == EXIT_FAILURE)
	//	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}