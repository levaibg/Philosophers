/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:49:01 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/11 17:44:53 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	philo;

	innit_arg(&data, &philo);
	if (pars_innit(&data, &philo, ac, av) == 1)
		return (1);
	philo_thread(&data, &philo);
	create_thread(&philo, &data);
	if (asvp(&data, &philo) == 1)
	{
		phreelo(&data, &philo);
		return (1);
	}
	phreelo(&data, &philo);
	return (0);
}
