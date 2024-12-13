/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:50:15 by lloginov          #+#    #+#             */
/*   Updated: 2024/12/12 15:40:32 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	if(gettimeofday(&tv, NULL) == -1)
	{
		printf("Error : gettimeofday() error\n");
		return(-1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}


void	innit_var2(t_philo *philo, t_data *data)
{
	data->time_die = 0;
	data->time_eat = 0;
	philo->id = 0;
	philo->nb_forks = 0;
	philo->nb_philo = 0;
	philo->data = NULL;
	philo->dead = 0;
	data->start_time = 0;
	philo->right_fork = NULL;
	// philo->printff = NULL;
	// philo->thread = NULL;
	data->forks = NULL;
}

int	innit_philo(int ac, char **av, t_data *data, t_philo *philo)
{
	if(ac == 6)
	{
		philo->must_eat = ft_atoi(av[5]);
		if(philo->must_eat <= 0)
		{
			printf(RED "Error : Must eat should be positive" NC);
			return(1);
		}
	}
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	philo->nb_philo = ft_atoi(av[1]);
	philo->nb_forks = philo->nb_philo;
	data->start_time = get_time();
	data->philo = philo;
	// printf("%d\n",ephilo->nb_forks);
	return(0);
}
void assign_philo(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_mutex_init(&data->philo[i].left_fork, NULL);
		i++;
	}

	i = 0;
	while (i < philo->nb_philo)
	{
		data->philo[i].id = i + 1;
		if (i == 0)
			data->philo[i].right_fork = &data->philo[philo->nb_philo - 1].left_fork;
		else
			data->philo[i].right_fork = &data->philo[i - 1].left_fork;

		data->philo[i].data = data;
		data->philo[i].last_meal = 0;
		data->philo[i].meal_count = 0;

		// printf("Philosopher %d: left_fork=%p, right_fork=%p\n", 
		//        data->philo[i].id, 
		//        &data->philo[i].left_fork, 
		//        data->philo[i].right_fork);

		i++;
	}

	pthread_mutex_init(&data->printff, NULL);

}

void phree(t_data *data)
{
	int i;

	i = 0;
	if(data->forks)
	{
		while(i < data->philo->nb_forks)
		{
			if(&data->forks[i])
				pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	// if(philo->thread)
	// 	free(philo->thread);
}
