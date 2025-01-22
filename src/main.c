/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:03:03 by ayarab            #+#    #+#             */
/*   Updated: 2025/01/20 17:17:25 by ayarab           ###   ########.fr       */
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
	printf("{%s}\n", cube3d.EA);
	printf("{%s}\n", cube3d.SO);
	printf("{%s}\n", cube3d.WE);
	printf("{%s}\n", cube3d.NO);
    return (ft_fail_free(&cube3d),EXIT_SUCCESS);
}


		/*
			printf("%s\n", cube3d.NO);
			printf("%s\n", cube3d.WE);
			printf("%s\n", cube3d.SO);
			printf("%s\n", cube3d.EA);
		*/