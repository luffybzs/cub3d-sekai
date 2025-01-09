/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:03 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/09 21:44:04 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"


int ft_check_av1(char *av1, t_cub3d *cube3d)
{
	int i;
	int point;

	i = 0;
	point = ft_strlen(cube3d->av1) - 4;
	if (ft_strlen(cube3d->av1) < 4)
		return (EXIT_FAILURE);
	if (ft_strcmp(&cube3d->av1[point], ".cub") != 0)
		return (EXIT_FAILURE);
	if (cube3d->av1[point - 1] == '/')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
int ft_search_info(char *av1, t_cub3d *cub3d)
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
        if (line[0] == '\n')
            return (free(line), free(res), EXIT_FAILURE);
        res = ft_strjoin_free(res, line);
        if (!res)
            return (free(line), EXIT_FAILURE);
        free(line);
        line = get_next_line(fd);
    }
    cub3d->all_maps = ft_split(res, '\n');
    if (!cub3d->all_maps)
        return (free(res), EXIT_FAILURE);
    return (free(res), EXIT_SUCCESS);
}

int ft_fill_data(int ac, char **av, t_cub3d *cub3d)
{
    cub3d->ac = ac;
    cub3d->av1 = av[1];
    if (ft_check_av1(cub3d->av1, cub3d) == EXIT_FAILURE)
        return (ft_putstr_fd("Error\n", 2) ,EXIT_FAILURE);
    if (ft_search_info(cub3d->av1, cub3d) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    t_cub3d cube3d;
    if (ac != 2)
        return(1);
    if (ft_fill_data(ac, av, &cube3d) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}