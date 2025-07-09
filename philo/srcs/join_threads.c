/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:25:22 by miniklar          #+#    #+#             */
/*   Updated: 2025/07/09 21:55:44 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	join_monitor_thread(pthread_t monitor)
{
	if (pthread_join(monitor, NULL) != 0)
	{
		perror("join monitor error");
		return (false);
	}
	return (true);
}

int	join_thread(pthread_t *threads, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			perror("join error");
			return (1);
		}
		i++;
	}
	return (0);
}
