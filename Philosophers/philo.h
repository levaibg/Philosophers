/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:08:21 by lloginov          #+#    #+#             */
/*   Updated: 2024/11/05 12:08:34 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

#define NC "\e[0m"		  // reset color
#define YELLOW "\e[1;33m" // yellow
#define BLUE "\e[1;34m"	  // bleu
#define GREEN "\e[1;32m"  // green
#define RED "\e[1;31m"	  // red

typedef struct s_time
{
	int time_eat;
	int time_die;
	int time_sleep;
}	t_time;

typedef struct t_philo
{
	int ID;
	int nb_forks;
	int nb_philo;
	char *philo;
	pthread_t thread;
}	t_philo;

// philo

//philo_utils

int get_time(void);
void	innit_var(t_time *time);
int	ft_atoi(const char *str);
void	phree(t_time *time, t_philo *philo);

//philo
int	innit_philo(int ac, char **av, t_time *time, t_philo *philo);

// main
int main(int ac, char **av);

#endif