/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:03:56 by lomont            #+#    #+#             */
/*   Updated: 2025/04/08 03:34:12 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_threads(t_philo *data)
{
	int j;

	j = 0;
	while (j != data->nb_philo)
	{
		if (pthread_create(&data->philo[j].threads, NULL, philo, &data->philo[j]) != 0)
			printf("INIT FAILED\n");
		else
		{
			data->philo[j].thread_num = j + 1;
			printf("INIT SUCCESS\n");
			pthread_join(data->philo[j].threads, NULL);
		}
		j++;
	}
}

void init_data(t_philo *data, char **argv)
{
	t_fork *fork;
	t_thread *threads_test;
	int i;

	i = 0;
	data->nb_philo = ft_atoi(argv[1]);
	fork = malloc(sizeof(*fork));
	threads_test = malloc(sizeof(*threads_test) * data->nb_philo);
	if (!threads_test || !fork)
	{
		printf("data | fork malloc failed");
		exit(EXIT_FAILURE);
	}
	while (i < data->nb_philo)
	{
		threads_test[i].mutex = fork;
		printf("SUCCESS !\n");
		i++;
	}
	fork->time_to_die = ft_atol(argv[2]);
	fork->time_to_eat = ft_atoi(argv[3]);
	fork->time_to_sleep = ft_atoi(argv[4]);
	if (pthread_mutex_init(&fork->mutex, NULL) != 0 ||
		pthread_mutex_init(&fork->mutex1, NULL) != 0)
	{
		printf("MUTEX INIT FAIL");
		exit(EXIT_FAILURE);
	}
	data->mutex = fork;
	data->philo = threads_test;
	//(*data)->count_eat_philo = NULL; //argv[5]
}

int	main(int argc, char **argv)
{
	t_philo data;

	if (argc == 6)
	{
		init_data(&data, argv);
		create_threads(&data);
		printf("c'est bon mon chef!\n");
	}
	else
		printf("c'est ok, tu es sorti\n");
	//free(data.philo->threads); //TODO free all threads
	return (0);
}
