/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:04:22 by lomont            #+#    #+#             */
/*   Updated: 2025/07/01 15:17:38 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <errno.h>

typedef struct s_philo
{
	int				nb_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_philo_needs_to_eat;
	int				index_philo;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct	s_philo *next;
}				t_philo;

void				*routine(void *arg);
void				check_parsing(int argc, char **argv);
void				ft_alloc_mutex(t_philo *philo);

// Utils

void				free_all(t_philo *philo, pthread_t *threads);
void				ft_putstr_fd(char *s, int fd);
void				print_error(char *str);
bool				ft_isdigit(int c);
long				ft_atol(const char *str);
void				free_array(pthread_mutex_t **array);
t_philo				*fill_philo(t_philo *node, int argc, char **argv);


// t_gims ciel;
// t_gims ferrari_vert;
// t_GIMS DECOUVERT_MAUVAI_REVE;

//printf("%lld %d is thinking", time, philo.thread_num);
//printf("%lld %d has taken a fork\n", time, philo.thread_num);
//printf("%lld %d is eating\n", time, philo.thread_num);
//printf("%lld %d died\n", time, philo.thread_num);

#endif
