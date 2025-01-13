/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:21:02 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/13 17:34:55 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->full_lock);
	if (philo->data->full_count == philo->data->nb_philo)
	{
		pthread_mutex_unlock(&philo->data->full_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->full_lock);
	pthread_mutex_lock(&philo->data->deadd);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->deadd);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->deadd);
	if (printlock(philo, "is sleeping") == 1)
		return (1);
	usleep(philo->data->time_sleep * 1000);
	return (0);
}

int	test(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->full_lock);
	if (philo->data->must_eat != 0)
	{
		if (philo->data->full_count == philo->data->must_eat)
		{
			pthread_mutex_unlock(&philo->data->full_lock);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->data->full_lock);
	return (0);
}

int	mutex_fork_innit(t_data *data, int i)
{
	if (pthread_mutex_init(&data->philo[i].left_fork, NULL) == -1)
	{
		printf(RED "Error : " NC "mutex creation error\n");
		return (1);
	}
	return (0);
}
