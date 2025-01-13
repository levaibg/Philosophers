/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:48:31 by lloginov          #+#    #+#             */
/*   Updated: 2025/01/13 17:34:33 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define NC "\e[0m"		  // reset color
# define YELLOW "\e[1;33m" // yellow
# define BLUE "\e[1;34m"	  // bleu
# define GREEN "\e[1;32m"  // green
# define RED "\e[1;31m"	  // red
# define PURPLE "\033[0;35m" // violette

typedef struct t_philo
{
	int				eatean;
	int				id;
	int				full;
	int				nb_forks;
	int				p;
	int				meal_count;
	long long		last_meal;
	pthread_mutex_t	meal_c_lock;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	pthread_t		asvp;
	struct t_data	*data;
}	t_philo;

typedef struct t_data
{
	int				nb_philo;
	int				must_eat;
	int				dead;
	long long		start_time;
	int				time_eat;
	int				time_die;
	int				time_sleep;
	int				full_count;
	pthread_mutex_t	full_lock;
	pthread_mutex_t	eating;
	pthread_mutex_t	printff;
	pthread_mutex_t	deadd;
	t_philo			*philo;
}	t_data;

//innit philo

void				innit_arg(t_data *data, t_philo *philo);
int					pars_innit(t_data *data, t_philo *philo, int ac, char **av);
int					philo_thread(t_data *data, t_philo *philo);
int					assign_philo(t_data *data, t_philo *philo);

//philo utils
long long			get_time(void);
int					ft_atoi(const char *str);
int					phreelo(t_data *data, t_philo *philo);
int					printlock(t_philo *philo, char *msg);
void				solophilo(t_philo *philo);

//philo
int					create_thread(t_philo *philo, t_data *data);
void				*routine_philo(void *arg);
int					asvp(t_data *data, t_philo *philo);

//routine 
int					thinking(t_philo *philo);
int					eating(t_philo *philo);
int					eating_2(t_philo *philo);
int					morgue(t_philo *philo);

//routine2
int					sleeping(t_philo *philo);
int					test(t_philo *philo);
int					mutex_fork_innit(t_data *data, int i);

#endif