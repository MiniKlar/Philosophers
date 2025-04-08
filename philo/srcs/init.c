/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:28:32 by lomont            #+#    #+#             */
/*   Updated: 2025/04/09 00:30:35 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void init_mutex(t_fork *fork)
{
	if (pthread_mutex_init(&fork->mutex, NULL) != 0 ||
		pthread_mutex_init(&fork->mutex1, NULL) != 0)
	{
		printf("MUTEX INIT FAIL");
		exit(EXIT_FAILURE);
	}
}

static void init_times(t_fork *fork, char **argv)
{
	fork->time_to_die = ft_atol(argv[2]);
	fork->time_to_eat = ft_atoi(argv[3]);
	fork->time_to_sleep = ft_atoi(argv[4]);
	//fork->count_eat_philo = NULL; //argv[5]
}

void init_data(t_philo *data, char **argv)
{
	t_fork		*fork;
	t_thread	*threads_test;
	int			i;

	i = -1;
	data->nb_philo = ft_atoi(argv[1]);
	fork = malloc(sizeof(*fork));
	threads_test = malloc(sizeof(*threads_test) * data->nb_philo);
	if (!threads_test || !fork)
	{
		printf("data | fork malloc failed");
		exit(EXIT_FAILURE);
	}
	init_times(fork, argv);
	init_mutex(fork);
	while (++i < data->nb_philo)
		threads_test[i].mutex = fork;
	data->mutex = fork;
	data->philo = threads_test;
}
