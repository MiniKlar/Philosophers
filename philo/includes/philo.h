/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:04:22 by lomont            #+#    #+#             */
/*   Updated: 2025/04/02 04:34:19 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef	struct s_philo
{
	int nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	char *count_eat_philo;
}			t_philo;

int	ft_atoi(const char *str);

#endif
