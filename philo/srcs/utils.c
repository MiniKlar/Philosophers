/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 02:11:58 by lomont            #+#    #+#             */
/*   Updated: 2025/07/08 21:29:43 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
	{
		perror("write error");
		return ;
	}
}

void	print_message(unsigned long long i, t_philo *p, int code)
{
	char	*tmp;

	pthread_mutex_lock(p->dinner->dead_thread);
	pthread_mutex_lock(p->dinner->m_print);
	if (!p->dinner->is_dead)
	{
		tmp = ft_lltoa(i);
		ft_putstr_fd(tmp, 1);
		free(tmp);
		ft_putchar_fd(' ', 1);
		tmp = ft_itoa(p->index_philo);
		ft_putstr_fd(tmp, 1);
		free(tmp);
		if (code == 0)
			ft_putstr_fd(" is thinking\n", 1);
		else if (code == 1)
			ft_putstr_fd(" has taken a fork\n", 1);
		else if (code == 2)
			ft_putstr_fd(" is eating\n", 1);
		else if (code == 3)
			ft_putstr_fd(" is sleeping\n", 1);
	}
	pthread_mutex_unlock(p->dinner->m_print);
	pthread_mutex_unlock(p->dinner->dead_thread);
}

void	print_death(unsigned long long time, t_philo *p, int i)
{
	char	*tmp;

	pthread_mutex_lock(p->dinner->m_print);
	tmp = ft_lltoa(time);
	ft_putstr_fd(tmp, 1);
	free(tmp);
	ft_putchar_fd(' ', 1);
	tmp = ft_itoa(i);
	ft_putstr_fd(tmp, 1);
	free(tmp);
	ft_putstr_fd(" died\n", 1);
	pthread_mutex_unlock(p->dinner->m_print);
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

unsigned long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		ft_putstr_fd("Error gettimeofday", 2);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
