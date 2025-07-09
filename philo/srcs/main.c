/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:03:56 by lomont            #+#    #+#             */
/*   Updated: 2025/07/09 18:17:28 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_dinner	*dinner;
	t_philo		*philo;

	if (argc == 5 || argc == 6)
	{
		if (!check_parsing(argc, argv))
			return (1);
		if (fill_dinner(&dinner, argc, argv) == 1)
			return (free_philo(dinner, NULL), 1);
		if (fill_philo(&philo, dinner) == 1)
			return (free_philo(dinner, philo), 1);
		if (ft_philo(dinner, philo) == 1)
			return (free_philo(dinner, philo), 1);
		else
			free_philo(dinner, philo);
	}
	else if (argc < 5)
		return (ft_putstr_fd("Not enough arguments\n", 2), 1);
	else
		return (ft_putstr_fd("Too much arguments\n", 2), 1);
	return (0);
}
