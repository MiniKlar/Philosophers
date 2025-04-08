/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:03:56 by lomont            #+#    #+#             */
/*   Updated: 2025/04/09 00:32:06 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo data;

	if (argc == 6)
	{
		init_data(&data, argv);
		ft_threads(&data);
	}
	else
		printf("c'est ok, tu es sorti\n");
	free(data.mutex);
	free(data.philo); //TODO free all threads
	return (0);
}
