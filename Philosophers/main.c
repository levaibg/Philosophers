/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:08:14 by lloginov          #+#    #+#             */
/*   Updated: 2024/11/22 14:29:08 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;
	t_data data;
	if(parsing(ac, av) == 1)
		return(1);
	innit_philo(ac, av, &philo, &data);
	phree(&philo, &data);
	return (0);
}
