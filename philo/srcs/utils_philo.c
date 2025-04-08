/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 02:19:41 by lomont            #+#    #+#             */
/*   Updated: 2025/04/09 00:42:22 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long get_timeOD(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) != 0)
		exit(EXIT_FAILURE);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void *philo(void *arg)
{
	bool need_to_die;
	bool need_to_eat;
	bool need_to_sleep;
	unsigned long long time;
	unsigned long long time_to_die;
	unsigned long long time_to_eat;
	t_thread philo;

	philo = *(t_thread *) arg;
	need_to_die = false;
	need_to_eat = true;
	need_to_sleep = true;
	time = get_timeOD();
	while (need_to_die != true)
	{
		time_to_die = time + philo.mutex->time_to_die;
		time = get_timeOD();
		if (time >= time_to_die)
		{
			printf("%lld %d died\n", time, philo.thread_num);
			need_to_die = true;
			return (0);
		}
		else if (need_to_eat == true)
		{
			need_to_eat = false;
			if (pthread_mutex_lock(&philo.mutex->mutex)) // lock first fork
				printf("%lld %d is thinking", time, philo.thread_num);
			philo.mutex->fork = true;	// philo takes the fork
			printf("%lld %d has taken a fork\n", time, philo.thread_num); // print it
			if (pthread_mutex_lock(&philo.mutex->mutex1) != 0)
				printf("%lld %d is thinking", time, philo.thread_num);
			philo.mutex->fork2 = true;											//SAME FOR SECOND FORK
			printf("%lld %d has taken a fork\n", time, philo.thread_num);
			printf("%lld %d is eating\n", time, philo.thread_num);
			time = get_timeOD();
			time_to_eat = time + philo.mutex->time_to_eat;
			while (time < time_to_eat) //while philo didn't finish his time to eat
				time = get_timeOD();		//refresh time to verify conditions
			philo.mutex->fork = false;
			pthread_mutex_unlock(&philo.mutex->mutex); //release fork
			philo.mutex->fork2 = false;
			pthread_mutex_unlock(&philo.mutex->mutex1); // release 2nd fork
			printf("%lld %d is sleeping\n", time, philo.thread_num);
			if (usleep(philo.mutex->time_to_sleep) != 0)
				exit(EXIT_FAILURE);
			}
			need_to_eat = true;
		}
	return (0);
}
