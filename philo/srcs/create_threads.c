/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:24:25 by miniklar          #+#    #+#             */
/*   Updated: 2025/07/09 18:02:04 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	create_monitor_thread(pthread_t *monitor, t_philo *philo)
{
	if (pthread_create(monitor, NULL, &monitoring, (void *)philo) != 0)
	{
		perror("pthread creation error");
		return (false);
	}
	return (true);
}

int	create_thread(t_philo *philo, pthread_t *threads)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = philo;
	while (i < philo->dinner->nb_philo)
	{
		if (pthread_create(&threads[i], NULL, &routine, (void *)tmp) != 0)
		{
			perror("pthread creation error");
			return (1);
		}
		if (tmp->next)
			tmp = tmp->next;
		i++;
	}
	return (0);
}
