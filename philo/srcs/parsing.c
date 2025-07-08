/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:37:15 by lomont            #+#    #+#             */
/*   Updated: 2025/07/02 02:27:12 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_is_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || (!ft_isdigit(str[i]) && str[0] != '+' && str[0] != '-'))
			return (false);
		i++;
	}
	return (true);
}

bool	check_parsing(int argc, char **argv)
{
	int		i;
	long	n;

	i = 1;
	while (i < argc)
	{
		n = ft_atol(argv[i]);
		if (!check_is_only_digit(argv[i]))
		{
			ft_putstr_fd("One or more arguments are not only composed of digits\n", 2);
			return (false);
		}
		if (n < 0 || n > INT_MAX)
		{
			ft_putstr_fd("One or more arguments are not within 0 & INT_MAX\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}
