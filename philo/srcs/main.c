/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:03:56 by lomont            #+#    #+#             */
/*   Updated: 2025/04/02 04:38:59 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long convert_ms(long *time)
{
	return (*time * 1000);
}

void *get_timeOD(void *arg)
{
	struct timeval time;
	long time_ms;

	if (gettimeofday(&time, NULL) != 0)
		return (NULL);
	else
	{
		time_ms = convert_ms(&time.tv_sec);
		printf("\n%ld %d is sleeping\n",time_ms, *(int *)arg);
		usleep(5000000);
	}
	return (0);
}

void create_threads(pthread_t *threads, int i)
{
	int j;
	int *ptr;

	j = 0;
	ptr = &j;
	while (j != i)
	{
		printf("J = %d\n", j);
		if (pthread_create(&threads[j], NULL, get_timeOD, (void *)ptr) != 0)
			printf("INIT FAILED\n");
		else
		{
			printf("INIT SUCCESS\n");
			pthread_join(threads[j], NULL);
		}
		j++;
	}
}

void init_data(t_philo *data, char **argv)
{
	if (!data)
	{
		printf("data malloc failed");
		exit(EXIT_FAILURE);
	}
	(*data).nb_philo = ft_atoi(argv[1]);
	(*data).time_to_die = ft_atoi(argv[2]);
	(*data).time_to_eat = ft_atoi(argv[3]);
	(*data).time_to_sleep = ft_atoi(argv[4]);
	(*data).count_eat_philo = NULL; //argv[5]

}

int	main(int argc, char **argv)
{
	t_philo data;

	if (argc == 6)
	{
		init_data(&data, argv);
		pthread_t threads[data.nb_philo];
		create_threads(threads, data.nb_philo);
		printf("c'est bon mon chef!\n");
	}
	else
		printf("c'est ok, tu es sorti\n");
	return (0);
}
