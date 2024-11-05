/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:52:58 by lloginov          #+#    #+#             */
/*   Updated: 2024/11/05 12:07:18 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	innit_philo(int ac, char **av, t_time *time, t_philo *philo)
{
	int i;

	i = 1;
	time->time_die = ft_atoi(av[2]);
	time->time_eat = ft_atoi(av[3]);
	time->time_sleep = ft_atoi(av[4]);
	philo->nb_philo = ft_atoi(av[1]);
	philo->nb_forks = philo->nb_philo;
	while(i != philo->nb_philo)
	{
		philo->ID = i;
		i++;
	}
}

void	philo_thread(void)
{
	
}