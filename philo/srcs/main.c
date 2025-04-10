/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:03:56 by lomont            #+#    #+#             */
/*   Updated: 2025/04/11 01:02:55 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	data;

	if (argc == 5 || argc == 6)
	{
		check_parsing(argc, argv);
		init_data(&data, argv);
		ft_threads(&data);
		pthread_mutex_destroy(&data.mutex->fork1);
		pthread_mutex_destroy(&data.mutex->fork2);
		free(data.mutex);
		free(data.philo);
	}
	else if (argc < 5)
		printf("Not enough arguments\n");
	else
		printf("Too much arguments\n");
	return (0);
}
//TODO free all threads
