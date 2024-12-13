/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:53:43 by lloginov          #+#    #+#             */
/*   Updated: 2024/12/13 11:25:51 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parsing(int ac, char **av)
{
	if ((ac != 5 && ac != 6) ||  ft_atoi(av[1]) <= 1|| ft_atoi(av[2]) < 1
		|| ft_atoi(av[3]) < 1|| ft_atoi(av[4]) < 1)
	{
		printf(RED "Error" NC ": argumets error\n");
		return (1);
	}
	if(get_time() == -1)
		return(1);
	return(0);
}

int	philo_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * philo->nb_forks);
	if(!data->forks)
	{
		printf("Error : creation mutexe");
		return(1);
	}
	data->philo = malloc(sizeof(t_philo) * (philo->nb_philo));
	if(!data->philo)
	{
		printf("Error : malloc philo");
		free(data->forks);
		return(1);
	}	
	data->philo[i].nb_forks = philo->nb_forks;

	while(i < philo->nb_forks)
	{
		// printf("%d\n", data->philo->nb_forks);
		if(pthread_mutex_init(&data->forks[i], NULL) != 0)
		{	printf("Error : Mutex innit error");
			return(1);
		}
		i++;
	}
	assign_philo(data, philo);
	return(0);
}

int philo_create(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while(i != philo->nb_philo)
	{
		if(pthread_create(&data->philo[i].thread, NULL, &routine, &data->philo[i]) != 0)
		{
			printf(RED"Error" NC "de cration du thread\n");
			return(1);
		}
		// usleep(150);
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	return(0);
}

void	*routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;
	if(philo->id %2 == 0)
		usleep(philo->data->time_die * 500);

	// printf(" %d at %p\n", philo->id, &philo[i]);
	while(1)
	{
		printf("Last Meeal : %lld\n", philo->last_meal);
		if(dead(philo) == 1)
			return(NULL);
		if(thinking(philo) == 1)
			return(NULL);
		if(eating(philo) == 1)
			return(NULL);
		printf("Last Meeal : %lld\n", philo->last_meal);		
		if(sleeping(philo) == 1)
			return(NULL);
		break;
	}
	// printf("philo %d pense\n", philo->id);
	// philo->last_meal = get_time() - philo->data->start_time;
	// printf("derniere repasse %d\n", philo->last_meal);



	return(NULL);
}
//  if(pthread_create(&data->thread[i