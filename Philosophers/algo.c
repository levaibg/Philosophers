/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:03:40 by lloginov          #+#    #+#             */
/*   Updated: 2024/11/22 18:41:55 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking(t_data *data)
{
	if(data->philo->dead == 1)
	{
		lockclear(data, "philo died");
		return(1);
	}
	lockclear(data, "philo think");
	return(0);
}

int	eating(t_data *data)
{
	if(data->philo->dead == 1)
	{
		lockclear(data, "philo died");
		return(1);
	}

	return(0); 
}

int	slepping(t_data *data)
{
	return(0);
}

