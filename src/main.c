/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:03 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/11 16:33:46 by wdaoudi-         ###   ########.fr       */
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
	if (ft_search_just_map(cube3d) == EXIT_FAILURE)
		return (EXIT_FAILURE); 
	return (EXIT_SUCCESS);
}


void ft_fail_free(t_cub3d *cube3d)
{
	if (cube3d->EA)
		free(cube3d->EA);
	if (cube3d->NO)
		free(cube3d->NO);
	if (cube3d->WE)
		free(cube3d->WE);
	if (cube3d->SO)
		free(cube3d->SO);
	if (cube3d->F)
		free(cube3d->F);
	if (cube3d->C)
		free(cube3d->C);	
	if (cube3d->all_maps)
		ft_free_2d(cube3d->all_maps);
	return ;
}
		/*printf("%s\n", cube3d.NO);
	printf("%s\n", cube3d.F);
	printf("%s\n", cube3d.C);
		printf("%s\n", cube3d.WE);
		printf("%s\n", cube3d.SO);
		printf("%s\n", cube3d.EA);*/

int main(int ac, char **av)
{
    t_cub3d cube3d;
	int i = 0;

    if (ac != 2)
        return(1);
    if (ft_fill_data(ac, av, &cube3d) == EXIT_FAILURE)
		return (ft_fail_free(&cube3d),EXIT_FAILURE);
	
	while (cube3d.all_maps[i])
	{
		printf("%s\n", cube3d.all_maps[i]);
		i++;
	}
    return (ft_fail_free(&cube3d),EXIT_SUCCESS);
}

