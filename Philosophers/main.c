/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:08:14 by lloginov          #+#    #+#             */
/*   Updated: 2024/11/05 10:52:16 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_philo *philo;
	t_time *time;

	if(ac < 4 || ac > 6 || ft_atoi(av[1]) < 1)
	{
		printf("Error : argumets");
		return(1);
	}
	innit_philo(ac, av, &time, &philo);

	return(0);
}