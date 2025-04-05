/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 02:19:41 by lomont            #+#    #+#             */
/*   Updated: 2025/04/05 04:30:40 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long convert_ms(long *time)
{
	return (*time * 1000);
}

long get_timeOD(void)
{
	struct timeval time;
	long time_ms;

	if (gettimeofday(&time, NULL) != 0)
		exit(EXIT_FAILURE);
	else
		time_ms = convert_ms(&time.tv_sec);
	return (time_ms);
}

void *philo(void *arg)
{
	bool need_to_die;
	long time;
	long time_to_die;
	t_philo *data;

	data = (t_philo *) arg;
	need_to_die = false;
	time = get_timeOD();
	time_to_die = time + data->time_to_die;
	while (need_to_die != true)
	{
		time = get_timeOD();
		if (time >= time_to_die)
		{
			printf("%ld %d died\n", time, 1);
			need_to_die = false;
			return (0);
		}
	}
	return (0);
}
