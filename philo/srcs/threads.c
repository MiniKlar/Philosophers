/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:42:21 by miniklar          #+#    #+#             */
/*   Updated: 2025/07/08 19:19:58 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ft_alloc_mutex(t_dinner *dinner, pthread_mutex_t ***fork)
{
	int	i;

	i = 0;
	*fork = malloc(sizeof(pthread_mutex_t *) * (dinner->nb_philosophers + 1));
	if (!(*fork))
		return (ft_putstr_fd("error fork array malloc\n", 2), false);
	while (i < dinner->nb_philosophers)
	{
		(*fork)[i] = malloc(sizeof(pthread_mutex_t));
		if (!(*fork)[i])
		{
			free_array_mutex((*fork));
			return (ft_putstr_fd("error fork malloc\n", 2), false);
		}
		pthread_mutex_init((*fork)[i], NULL);
		i++;
	}
	(*fork)[i] = NULL;
	return (true);
}

void	give_fork(t_philo *philo, pthread_mutex_t **fork, int nb_philo)
{
	int			i;
	t_philo		*tmp;

	tmp = philo;
	i = 0;
	while (i < nb_philo)
	{
		tmp->left_fork = fork[i];
		if (nb_philo > 1 && i == 0)
			tmp->right_fork = fork[nb_philo - 1];
		else if (nb_philo == 1)
			tmp->right_fork = fork[0];
		else
			tmp->right_fork = fork[i - 1];
		if (tmp->next)
			tmp = tmp->next;
		i++;
	}
}

static bool	create_monitor_thread(pthread_t *monitor, t_philo *philo)
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
	int	i;
	t_philo *tmp;

	i = 0;
	tmp = philo;
	while (i < philo->dinner->nb_philosophers)
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

static bool	join_monitor_thread(pthread_t monitor)
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

int	destroy_mutex(pthread_mutex_t **fork, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_destroy(fork[i]) != 0)
		{
			perror("mutex destroy error");
			return (1);
		}
		free(fork[i]);
		i++;
	}
	free(fork);
	return (0);
}

int	ft_philo(t_dinner *dinner, t_philo *philo)
{
	pthread_t	*threads;
	pthread_t	monitor;
	pthread_mutex_t **fork;

	threads = malloc(sizeof(pthread_t) * dinner->nb_philosophers);
	if (!threads)
		return (ft_putstr_fd("error allocation threads", 2), 1);
	if (!ft_alloc_mutex(dinner, &fork))
		return (free_threads_fork(threads, NULL), 1);
	give_fork(philo, fork, dinner->nb_philosophers);
	if (create_thread(philo, threads) == 1)
		return (free_threads_fork(threads, fork), 1);
	if (!create_monitor_thread(&monitor, philo))
		return (free_threads_fork(threads, fork), 1);
	if (join_thread(threads, dinner->nb_philosophers) == 1)
		return (free_threads_fork(threads, fork), 1);
	if (!join_monitor_thread(monitor))
		return (free_threads_fork(threads, fork), 1);
	free_threads_fork(threads, fork);
	return (0);
}
