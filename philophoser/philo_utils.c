/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:14:23 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/13 17:22:04 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("Error : gettimeofday() error\n");
		return (-1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (number * sign);
}

int	phreelo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < philo->data->nb_philo)
	{
		data->philo[i].right_fork = NULL;
		pthread_mutex_destroy(&data->philo[i].left_fork);
		i++;
	}
	if (data->philo)
		free(data->philo);
	pthread_mutex_destroy(&data->deadd);
	pthread_mutex_destroy(&data->printff);
	pthread_mutex_destroy(&data->eating);
	pthread_mutex_destroy(&philo->meal_c_lock);
	pthread_mutex_destroy(&data->full_lock);
	return (1);
}

int	printlock(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->deadd);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->deadd);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->deadd);
	pthread_mutex_lock(&philo->data->full_lock);
	if (philo->data->must_eat != 0)
	{
		if (philo->data->full_count == philo->data->nb_philo)
		{
			pthread_mutex_unlock(&philo->data->full_lock);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->data->full_lock);
	pthread_mutex_lock(&philo->data->printff);
	printf("%lld %d %s\n", get_time()
		- philo->data->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->printff);
	return (0);
}

void	solophilo(t_philo *philo)
{
	printf("0 1 is thinking\n");
	printf("0 1 has taken a fork\n");
	usleep(philo->data->time_die * 1000);
	printf("%d 1 died\n", philo->data->time_die);
}
