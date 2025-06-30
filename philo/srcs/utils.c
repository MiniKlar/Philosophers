/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 02:11:58 by lomont            #+#    #+#             */
/*   Updated: 2025/06/29 23:09:25 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_array(pthread_mutex_t **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		if (write(fd, &*s, 1) == -1)
		{
			perror("Write error");
			exit(EXIT_FAILURE);
		}
		s++;
	}
}

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

bool	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (true);
	else
		return (false);
}

bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

long	ft_atol(const char *str)
{
	long	nb;
	int		sign;
	size_t	i;

	i = 0;
	nb = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if ((str[i] == '+' && str[i + 1] != '-'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	nb = nb * sign;
	return (nb);
}
