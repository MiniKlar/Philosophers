/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:04:22 by lomont            #+#    #+#             */
/*   Updated: 2025/03/30 06:39:53 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

#include "../LIB_C/LIB_C.h"

typedef	struct s_philo
{
	int nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	char *count_eat_philo;
}			t_philo;

#endif
