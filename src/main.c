/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:03 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/15 22:33:54 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/cub3d.h"

int main(int ac, char **av)
{
    t_cub3d cube3d = {0};
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