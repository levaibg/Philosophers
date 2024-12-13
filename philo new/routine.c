/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:48:37 by lloginov          #+#    #+#             */
/*   Updated: 2024/12/13 11:46:02 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int dead(t_philo *philo)
{
	if(get_time() - philo->data->start_time - philo->last_meal >=  philo->data->time_die)
	{
		print_lock(philo, "DEAD");
		printf("philo meal : %lld \n %lld \n %d\n", philo->data->start_time, philo->last_meal, philo->data->time_die );
		return(1);
	}
	return(0);
}

int thinking(t_philo *philo)
{
	if(dead(philo) == 1)
		return(1);
	print_lock(philo, "is thinking");
	return(0);
}

int	eating(t_philo *philo)
{
	if(dead(philo) == 1)
		return(1);
	pthread_mutex_lock(&philo->left_fork);
	print_lock(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_lock(philo, "has taken a fork");
	print_lock(philo, "is eating");
	usleep(philo->data->time_eat * 1000);
	philo->last_meal = get_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	
	return(0);
}

int	sleeping(t_philo *philo)
{
	if(dead(philo) == 1)
		return(1);
	print_lock(philo, "is sleeping");
	usleep(philo->data->time_sleep * 1000);
	return(0);
}