/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:00:43 by lloginov          #+#    #+#             */
/*   Updated: 2024/11/05 10:56:04 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv,NULL);
	
	return((tv.tv_sec * 1000) +(tv.tv_usec /1000)); // sec * 1000 == milisec, usec /1000 == milisec 
}
void	innit_var(t_time *time, t_philo *philo)
{
	time->time_die = 0;
	time->time_eat = 0;
	philo->ID = 0;
	philo->nb_forks = 0;
	philo->nb_philo = 0;
	philo->philo = NULL;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
	{
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number);
}

void	phree(t_time *time, t_philo *philo)
{
	int i;

	if(philo->philo)
	{
		free(philo->philo[i]);
		philo->philo = NULL;
	}
	
}
