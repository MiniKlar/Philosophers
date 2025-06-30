/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:28:32 by lomont            #+#    #+#             */
/*   Updated: 2025/06/29 18:23:39 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo, char **argv, int argc)
{
	philo->nb_philosophers = atoi(argv[1]);
	philo->time_to_die = atoi(argv[2]);
	philo->time_to_eat = atoi (argv[3]);
	philo->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		philo->nb_time_philo_needs_to_eat = atoi(argv[5]);
	else
		philo->nb_time_philo_needs_to_eat = -1;

}
