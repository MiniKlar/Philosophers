/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:04:22 by lomont            #+#    #+#             */
/*   Updated: 2025/07/09 18:03:04 by miniklar         ###   ########.fr       */
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
	int					index_nb_meals;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*die_time;
	struct s_philo		*next;
	struct s_dinner		*dinner;
}				t_philo;

typedef struct s_dinner
{
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_philo;
	int					index_philo_finish_to_eat;
	int					nb_philo_needs_to_eat;
	bool				is_dead;
	pthread_mutex_t		*check;
	pthread_mutex_t		*m_print;
}				t_dinner;

bool				check_parsing(int argc, char **argv);
bool				join_monitor_thread(pthread_t monitor);
bool				create_monitor_thread(pthread_t *monitor, t_philo *philo);
int					create_thread(t_philo *philo, pthread_t *threads);
int					join_thread(pthread_t *threads, int nb_philo);
int					ft_philo(t_dinner *dinner, t_philo *philo);
int					fill_philo(t_philo **node, t_dinner *dinner);
int					fill_dinner(t_dinner **dinner, int argc, char **argv);
void				*routine(void *arg);
void				*monitoring(void *arg);
void				free_philo(t_dinner *dinner, t_philo *philo);
void				print_message(unsigned long long i, t_philo *p, int code);
void				print_death(unsigned long long time, t_philo *p, int i);
void				free_array_mutex(pthread_mutex_t **array);
void				free_threads_fork(pthread_t *threads,
						pthread_mutex_t **fork);

// Utils

char				*ft_itoa(int n);
char				*ft_lltoa(long long n);
bool				ft_isdigit(int c);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
long				ft_atol(const char *str);
unsigned long long	get_time(void);

#endif

// t_gims ciel;
// t_gims ferrari_vert;
// t_GIMS DECOUVERT_MAUVAI_REVE;
