/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:02:38 by miniklar          #+#    #+#             */
/*   Updated: 2025/07/08 22:14:39 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_dinner *dinner, t_philo *philo)
{
	t_philo	*tmp;

	if (dinner)
	{
		pthread_mutex_destroy(dinner->m_print);
		pthread_mutex_destroy(dinner->check);
		free(dinner->check);
		free(dinner->m_print);
		free(dinner);
	}
	if (philo)
	{
		while (philo)
		{
			tmp = philo;
			pthread_mutex_destroy(philo->die_time);
			free(philo->die_time);
			philo = philo->next;
			free(tmp);
		}
	}
}

void	free_threads_fork(pthread_t *threads, pthread_mutex_t **fork)
{
	if (fork)
		free_array_mutex(fork);
	if (threads)
		free(threads);
}

void	free_array_mutex(pthread_mutex_t **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		pthread_mutex_destroy(array[i]);
		free(array[i]);
		i++;
	}
	free(array);
}
