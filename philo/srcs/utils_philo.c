/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 02:19:41 by lomont            #+#    #+#             */
/*   Updated: 2025/04/11 01:09:54 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		exit(EXIT_FAILURE);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	*philo(void *arg)
{
	t_thread			philo;
	unsigned long long	time;

	philo = *(t_thread *) arg;
	time = get_time();
	sleep(philo.thread_num);
	printf("TIME = %llu\n", time);
	pthread_mutex_destroy(&philo.mutex->fork1);
	pthread_mutex_destroy(&philo.mutex->fork2);
	pthread_exit(NULL);
	return (0);
}
