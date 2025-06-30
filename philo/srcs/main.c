/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:03:56 by lomont            #+#    #+#             */
/*   Updated: 2025/06/27 16:19:44 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
argv[1] = number of philosophers
argv[2] = time to die
argv[3] = time to eat
argv[4] = time to sleep
argv[5] = number of times each philosophers must eat
*/

int	main(int argc, char **argv)
{
	t_philo philo;

	if (argc == 5 || argc == 6)
	{
		check_parsing(argc, argv);
		init_philo(&philo, argv, argc);
		ft_alloc_mutex(&philo);
	}
	else if (argc < 5)
		printf("Not enough arguments\n");
	else
		printf("Too much arguments\n");
	return (0);
}
