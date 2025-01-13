/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:14:10 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/13 17:24:08 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->deadd);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->deadd);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->deadd);
	if (printlock(philo, "thinking") == 1)
		return (1);
	return (0);
}

int	forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (printlock(philo, "has taken a fork ") == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	pthread_mutex_lock(&philo->data->deadd);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->deadd);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->deadd);
	pthread_mutex_lock(&philo->left_fork);
	if (printlock(philo, "has taken a fork") == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
		return (1);
	}
	return (0);
}

int	forks2(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	if (printlock(philo, "has taken a fork ") == 1)
	{
		pthread_mutex_unlock(&philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(&philo->data->deadd);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->deadd);
		pthread_mutex_unlock(&philo->left_fork);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->deadd);
	pthread_mutex_lock(philo->right_fork);
	if (printlock(philo, "has taken a fork ") == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
		return (1);
	}
	return (0);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->deadd);
	if (philo->data->dead == 1)
	{
		pthread_mutex_unlock(&philo->data->deadd);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->deadd);
	if (philo->id % 2 != 0)
	{
		if (forks(philo) == 1)
			return (1);
	}
	else
	{
		if (forks2(philo) == 1)
			return (1);
	}
	if (printlock(philo, "is eating") == 1)
		return (1);
	if (eating_2(philo) == 1)
		return (1);
	return (0);
}

int	eating_2(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eating);
	philo->last_meal = get_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->eating);
	pthread_mutex_lock(&philo->meal_c_lock);
	pthread_mutex_lock(&philo->data->full_lock);
	if (philo->data->must_eat != 0)
	{
		philo->meal_count++;
		if (philo->data->full_count == philo->data->nb_philo)
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(&philo->left_fork);
			pthread_mutex_unlock(&philo->meal_c_lock);
			pthread_mutex_unlock(&philo->data->full_lock);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->data->full_lock);
	pthread_mutex_unlock(&philo->meal_c_lock);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	return (0);
}
