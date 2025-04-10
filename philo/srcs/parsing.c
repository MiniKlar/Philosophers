/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:37:15 by lomont            #+#    #+#             */
/*   Updated: 2025/04/11 00:09:18 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	arg_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && (str[i] != '+' && str[i] != '-'))
			return (false);
		i++;
	}
	return (true);
}

void	check_parsing(int argc, char **argv)
{
	int		i;
	long	n;

	i = 1;
	while (i < argc)
	{
		n = ft_atol(argv[i]);
		if (!arg_isdigit(argv[i]))
		{
			printf("One or more arguments are not only composed of digits\n");
			exit(EXIT_FAILURE);
		}
		if (n < 0 || n > INT_MAX)
		{
			printf("One or more arguments are not within 0 & INT_MAX\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
