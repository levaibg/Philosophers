/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:14:15 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/13 17:34:49 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	innit_arg(t_data *data, t_philo *philo)
{
	philo->id = 0;
	philo->nb_forks = 0;
	data->nb_philo = 0;
	philo->p = 0;
	data->must_eat = 0;
	philo->meal_count = 0;
	philo->last_meal = 0;
	data->dead = 0;
	data->start_time = 0;
	data->time_eat = 0;
	data->time_die = 0;
	data->time_sleep = 0;
	philo->right_fork = NULL;
	data->philo = philo;
	philo->data = data;
	philo->full = 0;
	philo->eatean = 0;
	data->full_count = 0;
}

int	parsing(t_data *data, t_philo *philo, int ac, char **av)
{
	(void)philo;
	if ((ac != 5 && ac != 6) || ft_atoi(av[1]) < 1 || ft_atoi(av[2])
		< 1 || ft_atoi(av[3]) < 1 || ft_atoi(av[4]) < 1)
	{
		printf(RED "Error" NC ": argumets error\n");
		return (1);
	}
	if (ac == 6)
	{
		if (ft_atoi(av[5]) < 1)
		{
			printf(RED "Error" NC ": argumets error(ac :6)\n");
			return (1);
		}
		else
			data->must_eat = ft_atoi(av[5]);
	}
	return (0);
}

int	pars_innit(t_data *data, t_philo *philo, int ac, char **av)
{
	if (parsing(data, philo, ac, av) == 1)
		return (1);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->philo->data->nb_philo = ft_atoi(av[1]);
	philo->p = data->philo->data->nb_philo;
	data->philo->nb_forks = data->philo->data->nb_philo;
	if (data->philo->data->nb_philo == 1)
	{
		solophilo(philo);
		return (1);
	}
	if (get_time() == -1)
		return (1);
	data->start_time = get_time();
	return (0);
}

int	philo_thread(t_data *data, t_philo *philo)
{
	pthread_mutex_init(&data->deadd, NULL);
	pthread_mutex_init(&data->printff, NULL);
	pthread_mutex_init(&data->eating, NULL);
	pthread_mutex_init(&philo->meal_c_lock, NULL);
	pthread_mutex_init(&data->full_lock, NULL);
	data->philo = malloc(sizeof(t_philo) * (philo->data->nb_philo));
	if (!data->philo)
	{
		printf(RED " Error : " NC "Malloc error");
		return (1);
	}
	if (assign_philo(data, philo) == 1)
		return (1);
	return (0);
}

int	assign_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (i++ < philo->data->nb_philo - 1)
	{
		if (mutex_fork_innit(data, i) == 1)
			return (1);
	}
	i = -1;
	while (i++ < philo->data->nb_philo - 1)
	{
		data->philo[i].id = i + 1;
		if (i == 0)
			data->philo[i].right_fork
				= &data->philo[philo->data->nb_philo - 1].left_fork;
		else
			data->philo[i].right_fork = &data->philo[i - 1].left_fork;
		data->philo[i].data = data;
		data->philo[i].last_meal = 0;
		data->philo[i].full = 0;
		data->philo[i].meal_count = 0;
	}
	return (0);
}
