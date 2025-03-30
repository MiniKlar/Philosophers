/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:03:56 by lomont            #+#    #+#             */
/*   Updated: 2025/03/30 06:40:49 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo *data;

	if (argc == 6)
	{
		data->nb_philo = ft_atoi(argv[2]);
		data->time_to_die = ft_atoi(argv[3]);
		data->time_to_eat = ft_atoi(argv[4]);
		data->time_to_sleep = ft_atoi(argv[5]);
		data->nb_philo = ft_atoi(argv[6]);
		printf("c'est bon mon chef!");
	}
	else
		printf("c'est ok, tu es sorti");
	(void)argv;
}
