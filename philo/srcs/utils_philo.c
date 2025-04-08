/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 02:19:41 by lomont            #+#    #+#             */
/*   Updated: 2025/04/08 03:38:32 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long convert_ms(long *time)
{
	return (*time / 1000);
}

long get_timeOD(void)
{
	struct timeval time;
	long time_ms;

	if (gettimeofday(&time, NULL) != 0)
		exit(EXIT_FAILURE);
	else
		time_ms = convert_ms(&time.tv_usec);
	return (time_ms);
}

void *philo(void *arg)
{
	bool need_to_die;
	bool need_to_eat;
	bool need_to_sleep;
	long time;
	long time_to_die;
	long time_to_eat;
	t_thread philo;

	philo = *(t_thread *) arg;
	need_to_die = false;
	need_to_eat = true;
	need_to_sleep = true;
	time = get_timeOD();
	printf("time to die =%ld\n", philo.mutex->time_to_die);
	printf("time to eat =%d\n", philo.mutex->time_to_eat);
	time_to_die = time + (long)(philo.mutex->time_to_die);
	time_to_eat = time + (long)(philo.mutex->time_to_eat);
	while (need_to_die != true)
	{
		time = get_timeOD();
		if (time >= time_to_die)
		{
			printf("%ld %d died\n", time, philo.thread_num);
			need_to_die = true;
			return (0);
		}
		else if (need_to_eat == true)
		{
			need_to_eat = false;
			printf("%ld %d is eating\n", time, philo.thread_num);
			printf(" TIME %ld and TIME TO EAT %ld\n", time, time_to_eat);
			pthread_mutex_lock(&philo.mutex->mutex);
			pthread_mutex_lock(&philo.mutex->mutex1);
			while (time < time_to_eat)
			{
				time = get_timeOD();
				philo.mutex->fork = true;
				philo.mutex->fork2 = true;
			}
			pthread_mutex_unlock(&philo.mutex->mutex);
			pthread_mutex_unlock(&philo.mutex->mutex1);
			if (need_to_sleep == true)
			{
				printf("%ld %d is sleeping\n", time, philo.thread_num);
				if (usleep(philo.mutex->time_to_sleep) != 0)
					exit(EXIT_FAILURE);
			}
			need_to_eat = true;
		}
	}
	return (0);
}
