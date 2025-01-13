/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:14:07 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/13 17:22:43 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		if (pthread_create(&data->philo[i].thread
				, NULL, routine_philo, &data->philo[i]) != 0)
		{
			printf(RED "Error : " NC "creation thread");
			return (1);
		}
		i++;
	}
	return (0);
}

void	*routine_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->time_die > philo->data->time_eat)
	{
		if (philo->id % 2 == 0)
			usleep(philo->data->time_eat * 500);
	}
	else if (philo->id % 2 == 0)
		usleep(philo->data->time_die * 500);
	while (1)
	{
		if (thinking(philo) == 1)
			return (NULL);
		if (eating(philo) == 1)
			return (NULL);
		if (sleeping(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

int	philo_status(t_data *data, t_philo *philo, int i)
{
	pthread_mutex_lock(&data->eating);
	if ((get_time() - data->start_time)
		- data->philo[i].last_meal >= philo->data->time_die + 3)
	{
		pthread_mutex_lock(&data->deadd);
		data->dead = 1;
		pthread_mutex_lock(&data->printff);
		printf("%lld %d " RED "died\n" NC, get_time()
			- data->start_time, data->philo[i].id);
		pthread_mutex_unlock(&data->printff);
		pthread_mutex_unlock(&data->deadd);
		pthread_mutex_unlock(&data->eating);
		return (1);
	}
	pthread_mutex_unlock(&data->eating);
	return (0);
}

int	manger_check(t_data *data, t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->meal_c_lock);
	pthread_mutex_lock(&data->full_lock);
	if (data->philo[i].meal_count == data->must_eat && data->philo[i].full != 1)
	{
		data->philo[i].full = 1;
		data->full_count++;
	}
	pthread_mutex_unlock(&philo->meal_c_lock);
	if (data->full_count == data->nb_philo)
	{
		pthread_mutex_lock(&data->deadd);
		data->dead = 1;
		pthread_mutex_unlock(&data->deadd);
		pthread_mutex_unlock(&data->full_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->full_lock);
	return (0);
}

int	asvp(t_data *data, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->data->nb_philo)
		{
			if (philo_status(data, philo, i) == 1)
				return (1);
			if (data->must_eat > 0)
			{
				if (manger_check(data, philo, i) == 1)
					return (1);
			}
			i++;
		}
	}
	return (0);
}
