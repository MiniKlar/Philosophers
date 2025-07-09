/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:29:41 by miniklar          #+#    #+#             */
/*   Updated: 2025/07/09 18:12:11 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	print_philo_has_finished(t_philo *philo)
{
	pthread_mutex_lock(philo->dinner->check);
	philo->dinner->is_dead = true;
	pthread_mutex_unlock(philo->dinner->check);
	ft_putstr_fd("All philosophers are fed!\n", 1);
}

static void	check_nb_of_philo_meals(t_philo **tmp)
{
	while (*tmp)
	{
		if ((*tmp)->index_nb_meals == (*tmp)->dinner->nb_philo_needs_to_eat)
			(*tmp) = (*tmp)->next;
		else
			break ;
	}
}

unsigned long long	*fill_time(t_philo *philo, unsigned long long *threads)
{
	t_philo	*tmp;
	int		i;

	i = 0;
	tmp = philo;
	threads = malloc(sizeof(unsigned long long) * philo->dinner->nb_philo);
	if (!threads)
		return (NULL);
	if (philo->dinner->index_philo_finish_to_eat
		== philo->dinner->nb_philo)
		return (free(threads), print_philo_has_finished(philo), NULL);
	while (i < philo->dinner->nb_philo)
	{
		check_nb_of_philo_meals(&tmp);
		if (!tmp)
			return (threads);
		pthread_mutex_lock(tmp->die_time);
		threads[i] = tmp->philo_die_time;
		pthread_mutex_unlock(tmp->die_time);
		if (tmp->next)
			tmp = tmp->next;
		i++;
	}
	return (threads);
}

static int	check_philo_died(t_philo *philo, unsigned long long *threads)
{
	int					i;
	unsigned long long	time;

	time = get_time();
	threads = fill_time(philo, threads);
	if (!threads)
		return (1);
	i = 0;
	while (i < philo->dinner->nb_philo)
	{
		if (threads[i] < time)
		{
			pthread_mutex_lock(philo->dinner->check);
			philo->dinner->is_dead = true;
			pthread_mutex_unlock(philo->dinner->check);
			print_death(time, philo, i + 1);
			free(threads);
			return (1);
		}
		else
			i++;
	}
	free(threads);
	return (0);
}

void	*monitoring(void *arg)
{
	t_philo				*philo;
	unsigned long long	*threads;

	philo = (t_philo *)arg;
	threads = NULL;
	while (!philo->dinner->is_dead)
	{
		if (check_philo_died(philo, threads) == 1)
			break ;
	}
	return (NULL);
}
