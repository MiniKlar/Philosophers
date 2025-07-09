/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:21:00 by miniklar          #+#    #+#             */
/*   Updated: 2025/07/09 21:58:10 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*create_node_philo(int i, t_dinner *dinner)
{
	t_philo	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->philo_die_time = get_time() + dinner->time_to_die;
	new_node->index_philo = i + 1;
	new_node->dinner = dinner;
	new_node->index_nb_meals = 0;
	new_node->die_time = malloc(sizeof(pthread_mutex_t));
	if (!new_node->die_time)
		return (NULL);
	pthread_mutex_init(new_node->die_time, NULL);
	new_node->next = NULL;
	return (new_node);
}

static t_philo	*ft_last_philo(t_philo *lst)
{
	t_philo	*tmp;

	if (lst == NULL)
		return (lst);
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

static void	ft_add_back_philo(t_philo **lst, t_philo *new)
{
	t_philo	*current;

	if (*lst == NULL)
		*lst = new;
	else
	{
		current = ft_last_philo(*lst);
		current->next = new;
	}
}

int	fill_philo(t_philo **node, t_dinner *dinner)
{
	t_philo	*new_node;
	int		i;

	i = 0;
	*node = NULL;
	while (i < dinner->nb_philo)
	{
		new_node = create_node_philo(i, dinner);
		if (!new_node)
			return (1);
		ft_add_back_philo(node, new_node);
		i++;
	}
	return (0);
}

int	fill_dinner(t_dinner **dinner, int argc, char **argv)
{
	(*dinner) = malloc(sizeof(t_dinner));
	if (!(*dinner))
		return (1);
	(*dinner)->nb_philo = atoi(argv[1]);
	(*dinner)->time_to_die = atoi(argv[2]);
	(*dinner)->time_to_eat = atoi (argv[3]);
	(*dinner)->time_to_sleep = atoi(argv[4]);
	if (argc == 6 && ft_atol(argv[argc - 1]) > 0)
		(*dinner)->nb_philo_needs_to_eat = atoi(argv[5]);
	else
		(*dinner)->nb_philo_needs_to_eat = -1;
	(*dinner)->index_philo_finish_to_eat = 0;
	(*dinner)->m_print = malloc(sizeof(pthread_mutex_t));
	if (!(*dinner)->m_print)
		return (1);
	pthread_mutex_init((*dinner)->m_print, NULL);
	(*dinner)->check = malloc(sizeof(pthread_mutex_t));
	if (!(*dinner)->check)
		return (1);
	pthread_mutex_init((*dinner)->check, NULL);
	(*dinner)->is_dead = false;
	return (0);
}
