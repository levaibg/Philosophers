/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:47:47 by lloginov          #+#    #+#             */
/*   Updated: 2024/12/11 13:22:11 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_philo philo;
	t_data data;
	innit_var2(&philo, &data);
	if(parsing(ac,av) == 1)
		return(1);
	if(innit_philo(ac, av, &data, &philo) == 1)
		return(1);
	if(philo_thread(&philo, &data) == 1)
		return(1);
	philo_create(&data, &philo);
	phree(&data);
	return(0);
}