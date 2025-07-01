/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:21:00 by miniklar          #+#    #+#             */
/*   Updated: 2025/07/01 15:16:16 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*create_node_philo(int i, int argc, char **argv)
{
	t_philo	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->nb_philosophers = atoi(argv[1]);
	new_node->time_to_die = atoi(argv[2]);
	new_node->time_to_eat = atoi (argv[3]);
	new_node->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		new_node->nb_time_philo_needs_to_eat = atoi(argv[5]);
	else
		new_node->nb_time_philo_needs_to_eat = -1;
	new_node->index_philo = i + 1;
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

t_philo	*fill_philo(t_philo *node, int argc, char **argv)
{
	t_philo	*new_node;
	int		i;

	i = 0;
	while (i < ft_atol(argv[1]))
	{
		new_node = create_node_philo(i, argc, argv);
		ft_add_back_philo(&node, new_node);
		i++;
	}
	return (node);
}
