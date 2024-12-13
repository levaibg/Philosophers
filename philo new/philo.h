/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:08:21 by lloginov          #+#    #+#             */
/*   Updated: 2024/12/13 16:40:40 by lloginov         ###   ########.fr       */
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

struct t_data;

typedef struct t_philo
{
	int				id;
	int				nb_forks;
	int				nb_philo;
	struct t_data	*data;
	int				must_eat;
	int				meal_count;
	long long		last_meal;
	pthread_mutex_t	left_fork;
	pthread_mutex_t *right_fork;
	pthread_t		thread;
}	t_philo;

typedef	struct t_data
{
	int				dead;
	long long		start_time;
	int				time_eat;
	int				time_die;
	int				time_sleep;
	pthread_mutex_t	eating;
	pthread_mutex_t	printff;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead;
	t_philo			*philo;
}	t_data;



//philo_utils
long long			get_time(void);
int					innit_philo(int ac, char **av, t_data *data, t_philo *philo);
void				assign_philo(t_data *data, t_philo *philo);
void 				phree(t_data *data);
void				innit_var2(t_philo *philo, t_data *data);

//philo_utils2
int					ft_atoi(const char *str);
int 	print_lock(t_philo *philo, char *msg);

//philo
int 				parsing(int ac, char **av);
int					philo_thread(t_philo *philo, t_data *data);
void				*routine(void *arg);
int philo_create(t_data *data, t_philo *philo);

//routine
int dead(t_philo *philo);
int thinking(t_philo *philo);
int	eating(t_philo *philo);
int	sleeping(t_philo *philo);

#endif