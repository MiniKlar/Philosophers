/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:32:09 by lomont            #+#    #+#             */
/*   Updated: 2025/04/09 01:57:59 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_threads(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].threads, NULL) != 0)
			printf("join FAILED\n");
		else
			return ;
		i++;
	}
}

static void	create_threads(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].threads, NULL, philo, &data->philo[i]) != 0)
			printf("INIT FAILED\n");
		else
			data->philo[i].thread_num = i + 1;
		i++;
	}
}

void	ft_threads(t_philo *data)
{
	create_threads(data);
	join_threads(data);
}
