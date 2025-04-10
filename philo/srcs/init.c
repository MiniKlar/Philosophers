/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:28:32 by lomont            #+#    #+#             */
/*   Updated: 2025/04/11 01:26:42 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_mutex(t_fork *fork)
{
	if (pthread_mutex_init(&fork->fork1, NULL) != 0
		|| pthread_mutex_init(&fork->fork2, NULL) != 0)
	{
		printf("MUTEX INIT FAIL");
		exit(EXIT_FAILURE);
	}
}

static void	init_times(t_fork *fork, char **argv)
{
	fork->time_to_die = ft_atol(argv[2]);
	fork->time_to_eat = ft_atol(argv[3]);
	fork->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		fork->count_eat_philo = ft_atol(argv[5]);
	else
		fork->count_eat_philo = -1;
}

void	init_data(t_philo *data, char **argv)
{
	t_fork		*fork;
	t_thread	*threads_test;
	int			i;

	i = -1;
	data->nb_philo = ft_atol(argv[1]);
	if (data->nb_philo == 0)
		print_error("Numbers of philosophers cannot be 0\n");
	fork = malloc(sizeof(*fork));
	threads_test = malloc(sizeof(*threads_test) * data->nb_philo);
	if (!threads_test || !fork)
		print_error("threads | fork malloc failed\n");
	init_times(fork, argv);
	if (fork->time_to_die == 0)
	{
		print_error("Time to die need to be above 0\n");
		free(fork);
		free(threads_test);
	}
	init_mutex(fork);
	while (++i < data->nb_philo)
		threads_test[i].mutex = fork;
	data->mutex = fork;
	data->philo = threads_test;
}
