/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:03:56 by lomont            #+#    #+#             */
/*   Updated: 2025/04/05 04:48:26 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void create_threads(t_philo *data)
{
	int j;

	j = 0;
	while (j != data->nb_philo)
	{
		if (pthread_create(&(*data).threads[j], NULL, philo, data) != 0)
			printf("INIT FAILED\n");
		else
		{
			printf("INIT SUCCESS\n");
			pthread_join((*data).threads[j], NULL);
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
	(*data).threads = malloc(sizeof(pthread_t) * (*data).nb_philo);

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
	free(data.threads);
	return (0);
}
