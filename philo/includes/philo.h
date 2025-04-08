/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:04:22 by lomont            #+#    #+#             */
/*   Updated: 2025/04/08 03:27:19 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex1;
	long			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	bool			fork;
	bool			fork2;
}		t_fork;

typedef struct s_thread
{
	t_fork		*mutex;
	pthread_t	threads;
	int			thread_num;
}			t_thread;

typedef	struct s_philo
{
	//char		*count_eat_philo;
	t_thread	*philo;
	t_fork		*mutex;
	int			nb_philo;
}			t_philo;

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
long	convert_ms(long *time);
long	get_timeOD(void);
void	*philo(void *arg);

#endif
