/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 02:19:41 by lomont            #+#    #+#             */
/*   Updated: 2025/07/08 21:30:16 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->die_time);
	philo->philo_die_time = get_time() + philo->dinner->time_to_die;
	pthread_mutex_unlock(philo->die_time);
	if (philo->index_philo % 2 == 0)
	{
		usleep(10000);
		pthread_mutex_lock(philo->die_time);
		philo->philo_die_time = get_time() + philo->dinner->time_to_die;
		pthread_mutex_unlock(philo->die_time);
	}
	while (1)
	{
		if (philo->dinner->is_dead)
			break;
		if (pthread_mutex_lock(philo->left_fork) == 0)
			print_message(get_time(), philo, 1);
		if (pthread_mutex_lock(philo->right_fork) == 0)
			print_message(get_time(), philo, 1);
		print_message(get_time(), philo, 2);
		pthread_mutex_lock(philo->die_time);
		philo->philo_die_time = get_time() + philo->dinner->time_to_die;
		pthread_mutex_unlock(philo->die_time);
		usleep(philo->dinner->time_to_eat * 1000);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		print_message(get_time(), philo, 3);
		usleep(philo->dinner->time_to_sleep * 1000);
		i++;
	}
	return (NULL);
}
