/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:04:22 by lomont            #+#    #+#             */
/*   Updated: 2025/04/11 01:28:50 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_fork
{
	pthread_mutex_t	fork1;
	pthread_mutex_t	fork2;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			count_eat_philo;
}		t_fork;

typedef struct s_thread
{
	t_fork		*mutex;
	pthread_t	threads;
	int			thread_num;
}			t_thread;

typedef struct s_philo
{
	t_thread	*philo;
	t_fork		*mutex;
	long		nb_philo;
}			t_philo;

void				print_error(char *str);
bool				ft_isdigit(int c);
long				ft_atol(const char *str);
unsigned long long	get_timeOD(void);
void				*philo(void *arg);
void				init_data(t_philo *data, char **argv);
void				ft_threads(t_philo *data);
void				check_parsing(int argc, char **argv);
// t_gims ciel;
// t_gims ferrari_vert;
// t_GIMS DECOUVERT_MAUVAI_REVE;

//printf("%lld %d is thinking", time, philo.thread_num);
//printf("%lld %d has taken a fork\n", time, philo.thread_num);
//printf("%lld %d is eating\n", time, philo.thread_num);
//printf("%lld %d died\n", time, philo.thread_num);

#endif
