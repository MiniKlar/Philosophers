/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 02:19:41 by lomont            #+#    #+#             */
/*   Updated: 2025/07/09 22:02:26 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_if_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dinner->check);
	if (philo->dinner->is_dead)
		return (pthread_mutex_unlock(philo->dinner->check), 1);
	pthread_mutex_unlock(philo->dinner->check);
	return (0);
}

static void	update_die_time(t_philo *philo)
{
	pthread_mutex_lock(philo->die_time);
	philo->philo_die_time = get_time() + philo->dinner->time_to_die;
	pthread_mutex_unlock(philo->die_time);
}

static int	philo_having_dinner(t_philo *philo)
{
	if (check_if_philo_dead(philo) == 1)
		return (1);
	if (philo->index_nb_meals == philo->dinner->nb_philo_needs_to_eat)
	{
		pthread_mutex_lock(philo->dinner->check);
		philo->dinner->index_philo_finish_to_eat += 1;
		return (pthread_mutex_unlock(philo->dinner->check), 1);
	}
	print_message(get_time(), philo, 0);
	if (pthread_mutex_lock(philo->left_fork) == 0)
		print_message(get_time(), philo, 1);
	if (philo->dinner->nb_philo == 1)
		return (pthread_mutex_unlock(philo->right_fork), 1);
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
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	update_die_time(philo);
	if (philo->index_philo % 2 == 0)
	{
		usleep(10000);
		update_die_time(philo);
	}
	while (1)
	{
		if (philo_having_dinner(philo) == 1)
			break ;
		philo->index_nb_meals += 1;
	}
	return (NULL);
}
