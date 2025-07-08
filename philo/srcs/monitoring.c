/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:29:41 by miniklar          #+#    #+#             */
/*   Updated: 2025/07/08 21:18:22 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	*fill_time(t_philo *philo, unsigned long long *threads)
{
	int	i;
	t_philo	*tmp;

	i = 0;
	tmp = philo;
	threads = malloc(sizeof(unsigned long long) * philo->dinner->nb_philosophers);
	if (!threads)
		return (NULL);
	while (i < philo->dinner->nb_philosophers)
	{
		pthread_mutex_lock(tmp->die_time);
		threads[i] = tmp->philo_die_time;
		pthread_mutex_unlock(tmp->die_time);
		if (tmp->next)
			tmp = tmp->next;
		i++;
	}
	return (threads);
}

void *monitoring(void *arg)
{
	t_philo				*philo;
	unsigned long long	*threads;
	unsigned long long	time;
	int					i;

	philo = (t_philo *)arg;
	threads = NULL;
	while (!philo->dinner->is_dead)
	{
		time = get_time();
		threads = fill_time(philo, threads);
		if (!threads)
			return (NULL);
		i = 0;
		while (i < philo->dinner->nb_philosophers)
		{
			if (threads[i] < time)
			{
				pthread_mutex_lock(philo->dinner->dead_thread);
				philo->dinner->is_dead = true;
				pthread_mutex_unlock(philo->dinner->dead_thread);
				print_death(time, philo, i + 1);
				break;
			}
			else
				i++;
		}
		free(threads);
	}
	return (NULL);
}
