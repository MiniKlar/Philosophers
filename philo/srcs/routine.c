/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 02:19:41 by lomont            #+#    #+#             */
/*   Updated: 2025/06/30 18:08:27 by miniklar         ###   ########.fr       */
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

void	*routine(void *arg)
{
	t_philo	philo;
	unsigned long long	time;

	philo = *(t_philo *)arg;
	(void)philo;
	time = get_time();
	printf("Time = %lld\n", time);
	sleep(3);
	ft_putstr_fd("Ending\n", 1);
	return (0);
}
