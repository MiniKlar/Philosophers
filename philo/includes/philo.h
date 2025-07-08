/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:04:22 by lomont            #+#    #+#             */
/*   Updated: 2025/07/08 21:30:32 by miniklar         ###   ########.fr       */
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
	unsigned long long	philo_die_time;
	int					index_philo;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*die_time;
	struct	s_philo 	*next;
	struct	s_dinner	*dinner;
}				t_philo;

typedef struct s_dinner
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_philosophers;
	int					nb_time_philo_needs_to_eat;
	bool				is_dead;
	pthread_mutex_t		*dead_thread;
	pthread_mutex_t		*m_print;
}				t_dinner;

void				*monitoring(void *arg);
void				*routine(void *arg);
bool				check_parsing(int argc, char **argv);
int					ft_philo(t_dinner *dinner, t_philo *philo);

// Utils

void				free_philo(t_dinner *dinner, t_philo *philo);
void				ft_putstr_fd(char *s, int fd);
void				print_message(unsigned long long i, t_philo *p, int code);
void				print_death(unsigned long long time, t_philo *p, int i);
bool				ft_isdigit(int c);
long				ft_atol(const char *str);
void				free_array_mutex(pthread_mutex_t **array);
void				free_threads_fork(pthread_t *threads, pthread_mutex_t **fork);
int					fill_philo(t_philo **node, t_dinner *dinner);
int					fill_dinner(t_dinner **dinner, int argc, char **argv);
unsigned long long	get_time(void);
char				*ft_lltoa(long long n);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);


// t_gims ciel;
// t_gims ferrari_vert;
// t_GIMS DECOUVERT_MAUVAI_REVE;

#endif
