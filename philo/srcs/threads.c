/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:42:21 by miniklar          #+#    #+#             */
/*   Updated: 2025/07/01 15:16:32 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_threads(t_philo *philo, pthread_mutex_t **fork);

void	ft_alloc_mutex(t_philo *philo)
{
	int				i;
	pthread_mutex_t **fork;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t *) * philo->nb_philosophers);
	if (!fork)
		print_error("error fork malloc");
	while (i < philo->nb_philosophers)
	{
		fork[i] = malloc(sizeof(pthread_mutex_t));
		if (!fork[i])
			print_error("error fork malloc");
		pthread_mutex_init(fork[i], NULL);
		printf("mutex allocated\n");
		i++;
	}
	ft_threads(philo, fork);
}

void	give_fork(t_philo *philo, pthread_mutex_t **fork)
{
	int		i;
	t_philo *tmp;

	tmp = philo;
	i = 0;
	while (i < tmp->nb_philosophers)
	{
		tmp->left_fork = fork[i];
		if (tmp->nb_philosophers > 1 && i == 0)
			tmp->right_fork = fork[tmp->nb_philosophers - 1];
		else if (tmp->nb_philosophers && i == tmp->nb_philosophers - 1)
			tmp->right_fork = fork[0];
		else if (tmp->nb_philosophers == 1)
			tmp->right_fork = fork[0];
		else
			tmp->right_fork = fork[i + 1];
		i++;
		if (tmp->next)
			tmp = tmp->next;
	}
}

int	create_thread(t_philo *philo, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < philo->nb_philosophers)
	{
		if (pthread_create(&threads[i], NULL, &routine, (void *)philo) != 0)
		{
			perror("pthread creation error");
			exit(EXIT_FAILURE);
		}
		else
			ft_putstr_fd("Thread successfully created!\n", 1);
		if (philo->next)
			philo = philo->next;
		i++;
	}
	return (0);
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
			ft_putstr_fd("pthread join failed\n", 2);
			exit(EXIT_FAILURE);
		}
		else
			ft_putstr_fd("Thread successfully joined!\n", 1);
		i++;
	}
	return (0);
}

void	destroy_mutex(pthread_mutex_t **fork, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_destroy(fork[i]) != 0)
		{
			perror("mutex destroy error");
			exit(EXIT_FAILURE);
		}
		free(fork[i]);
		i++;
	}
	free(fork);
}

int	ft_threads(t_philo *philo, pthread_mutex_t **fork)
{
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * philo->nb_philosophers);
	if (!threads)
		print_error("error allocation threads");
	give_fork(philo, fork);
	create_thread(philo, threads);
	join_thread(threads, philo->nb_philosophers);
	destroy_mutex(fork, philo->nb_philosophers);
	free_all(philo, threads);
	exit(EXIT_SUCCESS);
}
