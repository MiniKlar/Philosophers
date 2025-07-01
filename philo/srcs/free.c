/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:02:38 by miniklar          #+#    #+#             */
/*   Updated: 2025/07/01 15:15:50 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philo, pthread_t *threads)
{
	t_philo *tmp;

	while (philo)
	{
		tmp = philo;
		philo = philo->next;
		free(tmp);
	}
	free(threads);
}
